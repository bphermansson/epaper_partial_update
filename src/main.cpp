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
  partialRefresh(20, 50, 60, 20, 1, 14, String(updateCounter));
  partialRefresh(45, 50, 80, 25, 2, 18, String(updateCounter));
  partialRefresh(70, 50, 100, 30, 3, 24, String(updateCounter));
  partialRefresh(95, 50, 60, 30, 4, 32, String(updateCounter));
  partialRefresh(120, 50, 80, 35, 5, 42, String(updateCounter));
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) { 
    previousMillis = currentMillis;
    updateCounter++;

    if (updateCounter >= 5) {
      fullRefresh(20, 20, "Partial refresh demo!");
      updateCounter = 0; // Nollställ räknaren
    } 
    else {
      partialRefresh(20, 50, 60, 20, 1, 14, String(updateCounter));
      partialRefresh(45, 50, 80, 25, 2, 18, String(updateCounter));
      partialRefresh(70, 50, 100, 30, 3, 24, String(updateCounter));
      partialRefresh(95, 50, 60, 30, 4, 32, String(updateCounter));
      partialRefresh(120, 50, 80, 35, 5, 42, String(updateCounter));
    }
  }
}