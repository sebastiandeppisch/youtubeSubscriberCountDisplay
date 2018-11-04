#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>   
#include <WiFiManager.h> 
#include <ESP8266HTTPClient.h>

#include "LedControl.h"
#include "ArduinoJson.h"


//put the name of the channel and your google-api key here
const String CHANNEL = "";
const String APIKEY = "";
//---- 


const String API="https://www.googleapis.com/youtube/v3/channels?part=statistics";
const char*  HOST="www.googleapis.com";

LedControl lc=LedControl(13,14,16,1);

WiFiClientSecure client;
void setup() {
  Serial.begin(9600);
  
  lc.shutdown(0,false); //wakeup
  lc.setIntensity(0,8); //brightness
  lc.clearDisplay(0); //clear

  WiFiManager wifiManager; //use wifiManager to configure wifi ssid and password
  wifiManager.autoConnect();
}

uint32_t tenPow(uint8_t exponent){
    uint32_t result = 1;
    while (exponent--){
      result *= 10;
    }
    return result;
}

void setNumber(uint32_t number){
  for(uint8_t i=0;i<8;i++){
    uint32_t n=number;
    uint32_t exponent = tenPow(i);
    n = n / exponent;
    n = n % 10;
    if(i > 0 && n==0 && number < exponent){ //dont display leading zeros
      n = 16; // 16 e.g. is all off
    }
    lc.setDigit(0, i, n, false);
  }
}

bool firstTry = true;
void loop() { 
  if((WiFi.status() == WL_CONNECTED)) {
      client.connect(HOST, 443);
      client.print(String("GET ") + API+"&forUsername="+CHANNEL+"&key="+APIKEY + " HTTP/1.1\r\n" +
        "Host: " + HOST + "\r\n" +
        "User-Agent: BuildFailureDetectorESP8266\r\n" +
        "Connection: close\r\n\r\n");
      while (client.connected()) {
        String line = client.readStringUntil('\n');
        if (line == "\r") {
          break;
        }
      }
      String payload = client.readString();
      Serial.println(payload);
      StaticJsonBuffer<1000> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(payload);
      setNumber(root["items"][0]["statistics"]["subscriberCount"]);
      firstTry = false;
  }else{
    Serial.println("not connected");
    delay(1000);
  }
  if(!firstTry){ //there seems - sometimes- to a be problem on checking the fingerprint. So, just for the first try, dont wait between (failed) polls
    delay(60000);
  }
  
}
