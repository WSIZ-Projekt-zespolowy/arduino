

#include <NeoICSerial.h>
#include <FastLED.h>

#define LED_PIN     A4
#define NUM_LEDS    1

NeoICSerial HC12;
CRGB leds[NUM_LEDS];
string TOKEN = "01";
string A = ""

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  leds[0] = CRGB(0, 0, 0);
  FastLED.show();

  Serial.begin(9600);
  HC12.begin(9600);

  Serial.println("Serial initialization done.");
  HC12.println("Serial initialization done.");
}

void loop() {
  A = "";
  while (Serial.available()) {
    HC12.write(Serial.read());
  }
  while (HC12.available()) {
    char a = HC12.read();
    A += a;
    Serial.write(a);
  }
  if(A = TOKEN + "RED"){
    leds[0] = CRGB(255, 0, 0);
    FastLED.show();
  }
  else if(A = TOKEN + "GREEN"){
    leds[0] = CRGB(0, 255, 0);
    FastLED.show();
  }
  else if(A = TOKEN + "NULL"){
    leds[0] = CRGB(0, 0, 0);
    FastLED.show();
  }
}
