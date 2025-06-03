#define BLYNK_TEMPLATE_ID "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME "Device"

#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TinyGPSPlus.h>

char ssid[] = "Wifi love 2";
char pass[] = "88888888";
char auth[] = "o-HQPG7gl6SKJ8yElhLFcPLUePcvwX9k";

#define GPS_RX_PIN 16
#define GPS_TX_PIN 17
HardwareSerial GPSSerial(2);
TinyGPSPlus gps;

WidgetLCD lcd(V6);
double targetLat = 0.0;
double targetLon = 0.0;
bool targetSet = false;
bool alerted = false;

BLYNK_WRITE(V3) {
  targetLat = param.asDouble();
  targetSet = true;
  alerted = false;
}

BLYNK_WRITE(V4) {
  targetLon = param.asDouble();
  targetSet = true;
  alerted = false;
}

void setup() {
  Serial.begin(115200);
  GPSSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  Blynk.begin(auth, ssid, pass, "blynk.dke.vn", 8888);
}
String line1;
String line2;
void loop() {
  Blynk.run();
  while (GPSSerial.available() > 0) {
    gps.encode(GPSSerial.read());
  }
   lcd.clear();
    delay(100);             //Use it to clear the LCD Widget
    lcd.print(0, 0, line1);  // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
    lcd.print(0, 1, line2);

  if (gps.location.isUpdated()) {
    double curLat = gps.location.lat();
    double curLon = gps.location.lng();

    Blynk.virtualWrite(V1, String(curLat, 6));
    Blynk.virtualWrite(V2, String(curLon, 6));
    Blynk.virtualWrite(V5, curLat, curLon);

    line1 = "Lat:" + String(curLat, 4);
    line2 = "Lon:" + String(curLon, 4);

   

    if (targetSet) {
      double d = gps.distanceBetween(curLat, curLon, targetLat, targetLon);
      if (d > 1000.0) {
        String msg = "Thiết bị đã cách toạ độ mục tiêu hơn 1 km\n" + String(d / 1000.0, 2) + " km";
        Blynk.virtualWrite(V10, 0);
       
      }
      if (d <= 1000.0) {
        Blynk.virtualWrite(V10, 1);
        
      }
    }
  }else{

    lcd.print(0, 0, "GPS NOT VALID");
  }
}
