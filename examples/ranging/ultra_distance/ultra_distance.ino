//#include "Ultrasonic.h" // for the range finder
//#include <TM1637.h> // For the 4-difit display
//#include "DisplayHelper1637.h"

//#define CLK 2//pins definitions for TM1637 and can be changed to other ports
//#define DIO 3




#include "SevenSegmentTM1637.h"
 #include "Ultrasonic.h"
 
/* initialize global TM1637 Display object
*  The constructor takes two arguments, the number of the clock pin and the digital output pin:
* SevenSegmentTM1637(byte pinCLK, byte pinDIO);
*/
const byte PIN_CLK = 2;   // define CLK pin (any digital pin)
const byte PIN_DIO = 3;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

const byte PIN_TRIG = 30;
const byte PIN_ECHO = 32;
Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
int oldDistance = 0;
int currentDistance = 0;
int loopNo = 0;
int refresh= 1;
int idist(int a, int b){
  return a>b ? a-b : b-a;
}

// run setup code
void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  ultrasonic.setTimeout(40000UL); // or 40000UL for max range
  // display INIT on the display
  delay(1000);                // wait 1000 ms
};

// run loop (forever)
void loop() {
  loopNo++;
  if ( loopNo > 10) {
   
    refresh = 1;
  }
    
  oldDistance = currentDistance;
  currentDistance = ultrasonic.distanceRead();
  
  if (( refresh == 1) ||idist(currentDistance, oldDistance) >0) {
    display.clear(); // flickering -> must add a smoothing function
    display.print(ultrasonic.distanceRead());
    refresh = 0;
    loopNo = 0;
  }
  
  Serial.println(currentDistance);
  delay(200);                     // wait 200 ms
};
