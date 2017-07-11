# YouTube subcriber count Display  using ESP8266 and MAX7219 7-segment display module
## Description
This is a real simple YouTube Subscriber Display. You just need two things: 
 - ESP8266 - I recommend using the Wemos D1 mini module 
	- Buy here: [Aliexpress](http://s.click.aliexpress.com/e/M3BuvjQ)
 - MAX7219 7-segment module
	- Buy here: [Aliexpress]("http://s.click.aliexpress.com/e/A2jeuvf)

 almost no soldering needed! (You just need to solder the pinheader on the pcb)
## Hardware 
Connect the display and the ESP with jumper wires: 

| ESP generic 	| Wemos D1 Mini 	| Display Module 	|
| -------------	| -----------------	| -----------------	|
| *5V*			| 5V				| 	VCC				|
| GND			| G					| GND				|
| GPIO13 (MOSI)	| D7				| DIN				|
| GPIO16 		| D0				| CS				|
| GPIO14 (SCK)	| D5				| CLK				|

as you can see on the pictures below: 
![photo_2017-07-12_00-23-33](https://user-images.githubusercontent.com/3171655/28093694-d01c4f54-6698-11e7-8d02-2e1d96c91dc0.jpg) ![photo_2017-07-12_00-21-03](https://user-images.githubusercontent.com/3171655/28093693-d01ae6e6-6698-11e7-9e6c-5346dafc028a.jpg)
## Software
- Install Arduino and ESP8266 librarys: https://github.com/esp8266/Arduino/#installing-with-boards-manager
- Install WiFiManager library: https://github.com/tzapu/WiFiManager#install-through-library-manager
- Create an API key for the YouTube Data API v3: https://developers.google.com/youtube/v3/getting-started
- Put your API key (40(?) signs long) and the name of the YouTube Account (e.g. youtube.com/user/NAME => NAME) in the placeholder in the youtubeSubcriberDisplay.ino (line 12-13) e.g.:
	- API key: ABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890AB
	- YouTube URL: https://www.youtube.com/user/johnDoe 
```
const String CHANNEL = "johnDoe";
const String APIKEY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890AB";
```
Now you can upload the firmware to the ESP. After uploading you should see a new Wifi (without a password). Connect to it and enter your Wifi password on the captive portal (see the github page of the WiFiManager for more info).
The ESP connects now to your Wifi and after a few seconds the subscriber count should appear on the display. 
