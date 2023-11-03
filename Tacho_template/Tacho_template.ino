#include <FastLED.h>
#include <TimerOne.h>

#define LED_PIN     6           // LED pin
#define NUM_LEDS    12          // pocet LED
#define fan         5           // pin ventilatora

const byte interruptPin = 2;    // pin pre tacho
volatile int count = 0;         // pocitadlo pulzov
volatile int rpm = 0;           // hodnota RPM

CRGB leds[NUM_LEDS];


void setup() {

  // Inicializacia LED a seriovej komunikacie
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);
  delay(20);

  // Konstantna hodnota ventilatora
  pinMode(fan, OUTPUT);
  analogWrite(fan, 128);

  // Inicializacia externeho prerusenia
  attachInterrupt(digitalPinToInterrupt(interruptPin), adding, RISING);

  // Inicializacia vnutorneho casovaca
  Timer1.initialize();
  Timer1.attachInterrupt(Tacho);
  
}

void Tacho()
{
  // Tu naprogramujte vypocet otacok (RPM) a vypisanie hodnoty na obrazovku
}


void adding()
{
  // Tu naprogramujte inkrement pocitadla
}

void loop() {

  // LED koliesko
  for(int i = 0; i<=11; i++)
  {
    leds[i] = CRGB(0, 255, 0);
    if(i > 0)
    {
      leds[i-1] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    delay(20);   
    if(i == 11)
    {
      leds[11] = CRGB(0, 0, 0);
    }
  }
  
}
