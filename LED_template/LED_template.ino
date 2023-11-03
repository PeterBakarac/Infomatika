#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    100

int colors[3] = {0, 0, 0};

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);
  delay(20);

}


void loop() {

    for(int i = 0; i <=2; i++)
    {
      colors[i] = random(0, 255);
    }
    
    leds[0] = CRGB(colors[0], colors[1], colors[2]);
    FastLED.show();
    delay(1000);
}
