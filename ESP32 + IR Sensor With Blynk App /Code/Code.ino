//Prateek
//www.justdoelectronics.com
//https://www.youtube.com/@JustDoElectronics/videos

#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define SENSOR 14
#define ACTION 13

BlynkTimer timer;

char auth[] = "t7GpELfK9NWe9a8fg9TYNiyyjmac9Mp";
char ssid[] = "prateeksingh";
char pass[] = "kumar@12345";


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(ACTION, OUTPUT);
}

void sensor() {

  int L = digitalRead(SENSOR);

  if (L == 1) {
    Serial.println(" Obstacle detected");
    digitalWrite(ACTION, HIGH);
    WidgetLED LED(V1);
    LED.on();

  } else {

    Serial.println("  === All clear");
    digitalWrite(ACTION, LOW);
    WidgetLED LED(V1);
    LED.off();
  }
}

void loop() {
  sensor();
  Blynk.run();
  delay(200);
}