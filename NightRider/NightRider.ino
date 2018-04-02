/**
 * NightRider
 */
void loop() {
  nightRider(CRGB(255, 0, 0), CRGB(255, 255, 255), 3, 50);
}

/**
 * A nightrider effect
 * CRGB c
 *  color for the main group of LEDs
 *  default = CRGB(255, 0, 0)
 * CRGB c2
 *  color for the background
 *  default = CRGB(0, 0, 0);
 * int len
 *  length of the main group of LEDs
 *  default = 3
 * int delayTime
 *  time to wait before moving the main group of LEDs
 *  default = 50 (ms)
 */
void nightRider(CRGB c, CRGB c2, int len, int delayTime) {
  int i=0;
  for (int i=0; i<NUM_LEDS; i++) {  //FORWARD
    leds[i] = c;
    if (i-len >= 0) {
      leds[i-len] = c2;
    }
    FastLED.show();
    delay(delayTime);
  }
  for (int i=0; i<NUM_LEDS; i++) {  //BACKWARD
    leds[NUM_LEDS-i] = c;
    if ((NUM_LEDS-i) <= NUM_LEDS-len) {
      leds[(NUM_LEDS-i) + len - 1] = c2;
    }
    FastLED.show();
    delay(delayTime);
  }
}
