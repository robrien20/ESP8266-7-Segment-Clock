#include <Arduino.h>
#include <TM1637Display.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Module connection pins (Digital Pins)
#define CLK 5
#define DIO 4

// Wifi Credentials
const char *ssid     = "Your_SSID";
const char *password = "Your_Password";


const long utcOffsetInSeconds = -5*60*60;

// Debugging?
const bool debugging = true;

String console;

// brightness // time
byte brightness[] = {      0,  //  unused
                           0,  //  1am
                           0,  //  2am
                           1,  //  3am
                           1,  //  4am
                           1,  //  5am
                           1,  //  6am
                           1,  //  7am
                           2,  //  8am
                           3,  //  9am
                           4,  //  10am
                           4,  //  11am
                           4,  //  12pm
                           4,  //  1pm
                           4,  //  2pm
                           4,  //  3pm
                           4,  //  4pm
                           4,  //  5pm
                           3,  //  6pm
                           3,  //  7pm
                           2,  //  8pm
                           2,  //  9pm
                           1,  //  10pm
                           0,  //  11pm
                           0   //  12am 
                     };

byte data[4];
int loadData = 3;


TM1637Display display(CLK, DIO);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
    display.setBrightness(4);
    
    Serial.begin(115200);
    WiFi.begin(ssid, password);


    if( debugging) Serial.println( "Connecting to Wifi ...");
    while ( WiFi.status() != WL_CONNECTED ) {
         load(50, 50);
         if( debugging) Serial.print( ".");
    }
    timeClient.begin();
    timeClient.update();
    for( int y = 0; y++; y<100)
    {
    loading(50-3*sqrt(y));
    }
}

void loop()
{
      
      
      int minutes = timeClient.getMinutes();
      int seconds = timeClient.getSeconds();
      int hour = timeClient.getHours();
      int hour_12 = (hour+11)%12+1;
      
      display.setBrightness(brightness[hour]);      

          for( int s = seconds; s < 60; s++){
            
            if ( s % 2) {
              display.showNumberDecEx(minutes, 0, true, 2, 2);
              display.showNumberDecEx(hour_12, 0b01000000, false, 2, 0);
              if( debugging) Serial.println( String(hour) + ":" + String(minutes) +":" + String(s));
              delay(968);
            } 
            else {
              display.showNumberDecEx(minutes, 0, true, 2, 2);
              display.showNumberDecEx(hour_12, 0, false, 2, 0);
              if( debugging) Serial.println( String(hour) + " " + String(minutes) +" " + String(s));
              delay(968);
            }
            
          }
          
          minutes++;
          display.showNumberDecEx(minutes, 0, true, 2, 2);
          display.showNumberDecEx(hour_12, 0b01000000, false, 2, 0);
          if( debugging) Serial.println( String(hour) + " " + String(minutes) +" 0?");
          timeClient.update();

}

void load(int count, int frameDelay){
  for(int i = 0; i < count; i++){
    loading(frameDelay);
  }
}

void loading(int d){
      setData(loadData, (loadData << 3) % 63, loadData, (loadData << 3) % 63);
      loadData = (loadData << 1) % 63;
      delay(d); 
}

void setData(int a, int b, int c, int d){
      data[0] = a;
      data[1] = b;
      data[2] = c;
      data[3] = d;
   
      display.setSegments(data);
}
