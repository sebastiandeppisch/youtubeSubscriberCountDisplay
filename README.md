#YouTube subcriber count Display  using ESP8266 and MAX7219 7-segment display module
##Description
This is a real simple YouTube Subscriber Display. You just need two things: 
 - ESP8266 
 - - I recommend using the Wemos D1 mini module 
 - - Buy here: Amazon TODO Aliexpress TODO 
 - MAX7219 7-segment module
 - - Buy here: Amazon TODO Aliexpress TODO
 almost no soldering needed! (You just need to solder the pinheader on the pcb)
##Hardware 
Connect the display and the ESP with jumper wires: 
| ESP generic 	| Wemos D1 Mini 	| Display Module 	|
| ----------- 	| ------------- 	|	-------------- 	|
| (any 5V)		| 5V				| 	VCC				|
| GND			| G					| GND				|
| GPIO13 (MOSI)	| D7				| DIN				|
| GPIO16 		| D0				| CS				|
| GPIO14 (SCK)	| D5				| CLK				|
as you can see on the picture below: 
TODO 
##Software
- Install Arduino and ESP8266 librarys: https://github.com/esp8266/Arduino/#installing-with-boards-manager
- Install WiFiManager library: https://github.com/tzapu/WiFiManager#install-through-library-manager
- Create an API key for the YouTube Data API v3: https://developers.google.com/youtube/v3/getting-started
- Put your API key (40(?) signs long) and the name of the YouTube Account (e.g. youtube.com/user/NAME => NAME) in the placeholder in the youtubeSubcriberDisplay.ino (line 12-13)
- - e.g. API key: ABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890AB youTube url: https://www.youtube.com/user/johnDoe 
```
const String CHANNEL = "johnDoe";
const String APIKEY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890AB";
```
now you can upload the firmware to the ESP. Then you should see a new Wifi (without a password). Connect to it and enter your Wifi Password (see the github Page of the WiFiManager lib for more info). Then the ESP connects to your Wifi and after a few seconds the subscriber count should appear on the display. 