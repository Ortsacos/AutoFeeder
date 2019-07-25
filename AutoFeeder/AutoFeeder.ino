#include <Servo.h>

/***********************************************************************************
Small fish feeder

code is set to have the feeder run 1x per day. It runs once immediatley upon startup,
then waits 24 hours for next run. For testing comment out the DAY (24*HOUR) line
and uncomment Day (2*SECOND) line
*****************************************************************************************/

#define SECOND 1000L
#define MINUTE (60*SECOND)
#define HOUR (60*MINUTE)
#define DAY (24*HOUR) //uncomment for actual run
//#define DAY (2*SECOND) //test setup

const int SERVO_PIN = 3; //pin number for the led pin - this is 'const' since it will not change during code, and saves Arduino memory
const int FILL_DEGREE=30; //starting hole location, fill slider with fish food
const int DISPENSE_DEGREE=120; //dispensing hole location

Servo servo1;

//setup runs once when the Arduino is turned on
void setup()
{
delay(100);
servo1.attach(SERVO_PIN); //attach the servo on pin SERVO_PIN

} //setup() is done, go to loop()

//loop runs forever once setup is complete
void loop()
{
//******************************************************************************
//NOTE: YOU WILL HAVE TO CHANGE THESE VALUES based on your servo horn alignment.
//******************************************************************************

servo1.write(FILL_DEGREE); // tell servo to go to fill position
delay(500); // delay for 1 second
servo1.write(DISPENSE_DEGREE); // tell servo to go to dispense location
delay(500); 
servo1.write(FILL_DEGREE); // tell servo to go back to fill position 

delay(DAY); // delay for 1 day
}
