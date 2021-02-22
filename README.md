# ESP8266 7 Segment Digital Clock

This is a cheap digital wifi clock powered by an ESP8266 and a TM1637 4 digit 7 segment display. Time is grabbed on the minute via [NTPClient](https://github.com/arduino-libraries/NTPClient). Display brightness is updated based on the hour of the day (customizable in the source code) so as to be visible during the day and dim at night. Theres also a fun little startup animation which you can play around with. 

<h2>Materials:</h2>

1. NodeMCU ESP8266 (~$2.00)
2. TM1637(~$0.80)
3. Female to Female Jumper wire ribbon. (~$0.60)
4. Micro USB cable (~$2.00)
5. USB power adapter (~$10.00)

**Total: $15.40. Total if you have an extra micro USB and power adapter: ~$3.40**

*Prices from aliexpress. Any of these items can also be purchased from amazon for a higher price and faster shipping*

<h2>Schematic:</h2>

![image](https://github.com/robrien20/ESP8266-7-Segment-Clock/blob/main/pics/ESP8266-7-Segment-Clock%20Pinout.jpg)

<h2>Instructions:</h2>

1. If you do not have an arduino IDE installed, download latest [Arduino IDE](https://www.arduino.cc/en/software)
2. Open the source code, install any dependencies, update SSID/Password, update brightness vector (optional), update UTC offset (default is Eastern Time Zone)
3. Upload to esp8266

<h2>To do:</h2>

1. Implement [WiFiManager](https://github.com/tzapu/WiFiManager)
2. Add pics of the clock I put together.
