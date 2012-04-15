/*
 * ks0108 GLCDexample
 * (example sketch from original ks0108 library)
 *
 * Basic test code for the Arduino KS0108 GLCD library.
 * This code exercises a range of graphic functions supported
 * by the library and is an example of its use.
 * It also gives an indication of performance, showing the
 *  number of frames drawn per second.  
 */

#include <glcd.h>
#include "fonts/Arial14.h"         // proportional font
#include "fonts/SystemFont5x7.h"   // system font
#include "bitmaps/ArduinoIcon.h"     // bitmap 

/*
 * Check for small displays as this code was written
 * before small displays were supported.
 */
#if DISPLAY_HEIGHT < 64
#error ks0108 example requires a display at least 64 pixels tall
#endif
#if DISPLAY_WIDTH < 128
#error ks0108 example requires a display at least 128 pixels wide
#endif

void setup(){
  GLCD.Init(NON_INVERTED);   // initialise the library, non inverted writes pixels onto a clear screen
  GLCD.ClearScreen();  
  GLCD.DrawBitmap(ArduinoIcon, 32,0, BLACK); //draw the bitmap at the given x,y position
  GLCD.SelectFont(System5x7); // switch to fixed width system font 
  delay(1000);
  GLCD.ClearScreen();
  delay(250);
  //Setting up serial communication
  Serial.begin(115200);
  //setup screen vars
  GLCD.SelectFont(System5x7);
}

void  loop(){   // run over and over again
  if (Serial.available() >0) GLCD.print((char)Serial.read());
}
