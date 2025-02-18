#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 
#define PIN2       8
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 40 

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  strip2.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255)

  turnOnStrip(strip.Color(255,  0, 0), 50);
}


// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {
 //put custom animations in here
}


void turnOnStrip(uint32_t color, int wait) {
  //loop through the LEDs on the strip
  //and turn them on
  for(int i = 0; i<strip.numPixels(); i++) { 

    strip.setPixelColor(i, color);
    strip2.setPixelColor(i, color);         
                             
  }
  strip.show(); 
  strip2.show();                           
  delay(wait); 
}

