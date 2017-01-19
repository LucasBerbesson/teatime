/* Sweep
 by La Fabrique DIY <https://www.youtube.com/channel/UCV8D6u7_jkuGf_iUvNzXpmg/videos>

 modified 19 Jan 2017
 by Lucas Berbesson
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int count = 0;
int max_tea = 90;
int min_tea = 30;
int infusion_time = 1; // en minutes

int flag_left = max_tea + 5; 
int flag_right = max_tea - 5;

int infusion_time_ms = 90000;


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  myservo.write(min_tea);
  delay(infusion_time_ms);
  myservo.write(max_tea);
  delay(2000);
  for (count = 1; count <= 25; count += 1) {
    delay(150);
    myservo.write(flag_left);              
    delay(150);      
    myservo.write(flag_right);  
    if ((count % 5) == 0 ) {
      delay(2000);                  
    }
  }
    delay(160000);
}
