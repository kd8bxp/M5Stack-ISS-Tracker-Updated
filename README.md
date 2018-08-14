# M5Stack ISS Tracker Updated

Based on previous "Simple-ISS-Notification-System" for the DDuino and ESP8266 boards.  
https://github.com/kd8bxp/Simple-ISS-Notification-System  
Updated, and inspired by code by Giuliano Pisoni and the M5Stack-Core board.  
https://github.com/ccxx72/ISS-Tracker    
Hopefully I have improved on his great ideas.  
A small portion of code from Tom Igoe (Star Trek DS9 Theme Song), which was slightly shorten and modified  
to work with the M5Stack was also used.  
(Unfortuntally I don't remember where I found his original code.)  

## Installation

ESP32 Core Boards needs to be installed:   
https://github.com/espressif/arduino-esp32  

Libraries required:  
M5Stack Library https://github.com/m5stack/M5Stack  
ArduinoJson: https://github.com/bblanchon/ArduinoJson  
ESP32 WifiManager:  https://github.com/bbx10/WiFiManager/tree/esp32  
ESP32 WebServer: https://github.com/bbx10/WebServer_tng  
ESP32 DNSServer: https://github.com/bbx10/DNSServer_tng   

An API Key is needed from http://timezonedb.com This is used to get the GMT offset and local timezone  
information.  It is also used to update the system clock from time to time.  
(Add it to line 48 of the code.)  

## APIs used

We have to acknowledge the following APIs.  
http://open-notify.org - They currently provide all of the APIs for the ISS, and without this site, none of this could be done.  
Google Static Maps - *it should be noted currently we can still get static maps without a API key, this may change in the future.  
http://timezonedb.com - Used to get local timezone, GMT offset information, and from time to time to update the clock.  
http://ip-api.com - provides geolocation information based on the external IP address of your modem.  

* Some special notes here: I tried hard to find sites that didn't require API keys, to make the sketch as simple to use as possiable.  
Unfortunally I couldn't find a site that provided all the information timezonedb.com provides - I did find sites that provide the  
current time, but not the local offset, or the timezone. 
* Also note: I am looking for alterntives to Google Maps - Openstreetmaps has promise, but so far I've only been able to get the maps  
provided as PNG files, and unfortuntally the M5Stack can't display them.  

IF anyone knows any alternitives to try please let me know.  

## Updates and (Hopefully) Improvements

Other then needing an API key for timezonedb.com, the sketch doesn't/shouldn't need any setup.  
The sketch should create a captive portal if it can't connect to the internet, from there you can setup your WIFI.  
Once connected, the sketch will first send a request to ip-api.com and hopefully get a latitude and longitude that  
is somewhat close to your location.  
From the latitude/longitude it will next quary timezonedb.com for timezone information.  
Other Changes:  
1) On the map display, I added the apx distance the ISS from your location. I also added a clock that is in LOCAL time.  
2) The ISS location is updated about every 5 seconds, but the map display is only updated about every 10 seconds.  
I found that the ISS icon didn't really move all that much in that amount of time, on the small display. The ISS of course is  
moving very quickly.  
3) map display no longer clears and redraws, it just redraws over top of the old map, this has the illusion of the ISS moving when it is updated.  
4) Updated the pass prediction screen to include both UTC (GMT) time and Local time. Also changed how the information is presented slightly.  
Pass predictions are currently updated every 30 minutes or so - This will probably change.  
5) Added the "People In Space" screen. People in space is updated every hour or so - this may or may not change in future version.  
The number of People, names and which craft they are onboard is displayed on the "People In Space" page. - This may change in the future as well.  
6) The way the map "zoom" function was changed slightly and appears to be more stable. An upper limit of zoom level 5 was set, as well as a better  
check for the lower zoom level of zero.  
7) A "mode" was added, the "B" button which is the FUCN button now changes between (currently) MAP, PASS, PEOPLE. The Mode can be expanded upon within memory limits.  
 mode zero is map and is the default mode, mode one is pass predictions, and mode two is people in space.
8) A text only mode was tried, and didn't work, however the code for it is still in the sketch in hopes that one day I or someone will be able to add it.  
  Note: Text only was going to use a different ISS api, and beable to display some other information, that this version, or previous versions currently don't  
have access to.  
9) Part of Star Trek DS9 theme music was added at startup, and should also play when the ISS is within 950 miles or so of your location. (This is currently untested, and unknown if it works)  
10) Most sub-functions and functions where broken out into tabs in the Arduino IDE, with large sketches, I have found it to be a little easier to read/find/change code.  
11) The ESP32 RTOS is used to update the location of the ISS, people in space, and pass predictions. (I may change this to just the location of the ISS in the future).  

The Sketch uses 998254 bytes (76%) of program storage space. Maximum is 1310720 bytes.  
Global variables use 47604 bytes (14%) of dynamic memory, leaving 280076 bytes for local variables. Maximum is 327680 bytes.  

## Video

(Kind of a bad video)  
https://youtu.be/PchYZOv0TQg  

## Usage

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2018 LeRoy Miller  
inspired by code by Giuliano Pisoni Copyright (c) 2018   
portion of code from Tom Igoe (Star Trek DS9 Theme Song) (unknown)  

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
