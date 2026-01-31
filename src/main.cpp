#include <Arduino.h>
#include "epaper.h"

unsigned long previousMillis = 0;  
const long interval = 60000;// Varje minut
int updateCounter = 0; // Räknar uppdateringar
int x=20;
int y=50;
int w=150;
int h=15;

void setup() {
  Serial.begin(115200);
  delay(4000);

  Serial.println("Starting...");  
  initialiseDisplay();
  drawString(10, 10, "Partial refresh demo");
  partialRefresh(x, y, w, h, String(updateCounter));
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) { 
    previousMillis = currentMillis;
    updateCounter++;

    if (updateCounter >= 60) {
      fullRefresh(10, 10, "Refresh");
      updateCounter = 0; // Nollställ räknaren
    } 
    else {
      partialRefresh(x, y, w, h, String(updateCounter));
    }
  }
}