/* 
 *  The project has been tested with an Arduino Mega 2560 board
 *  The leds are lit one by one, so this kind of project could be used
 *  with a bigger number of leds and ideally could check the integrity 
 *  of most of the pins of the board as well as of many leds in parallel.
 *  
 *  It is a simple project good for starters.
 */

const int LED_ONE = 31;
const int LED_TWO = 33;
const int LED_THREE = 35;
const int LED_FOUR = 37;
const int LED_FIVE = 39;
const int DELAY_TIME=250;
const int LED_PINS[] = { LED_ONE,LED_TWO,LED_THREE,LED_FOUR,LED_FIVE};
const int LED_COUNT = 5;

void setup() {
  int pinIndex;
  
  for ( pinIndex = 0; pinIndex < LED_COUNT; pinIndex++){
    pinMode(LED_PINS[pinIndex],OUTPUT);
  }
  

}

void loop() {
  int pinIndex;
  for ( pinIndex = 0; pinIndex < LED_COUNT; pinIndex++){
    // Light up the leds one by one
   digitalWrite(LED_PINS[pinIndex], HIGH);
   delay(DELAY_TIME);
   digitalWrite(LED_PINS[pinIndex], LOW);
  }
   
  delay(DELAY_TIME);
}
