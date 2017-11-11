// rc_servo_sample1

#include <Servo.h>

Servo myservo1;
Servo myservo2;
//Servo myservo3;
//Servo myservo4;
//Servo myservo5;
//Servo myservo6;


int pos = 20;

void setup() {
  myservo1.attach( 0 );
  myservo2.attach( 2 );
  //myservo3.attach( 7 );
  //myservo4.attach( 6 );
  //myservo5.attach( 5 );
  //myservo6.attach( 4 );
  
}

void loop() {
  for ( pos = 180; pos > 0; pos -= 1 ) {
    myservo1.write( pos );
    delay( 15 );
  }
  
  for ( pos = 0; pos < 180; pos += 1 ) {
    myservo1.write( pos );
    delay( 15 );
  }
  
  
  for ( pos = 0; pos < 180; pos += 1 ) {
    myservo2.write( pos );
    delay( 15 );
  }
  
  for ( pos = 180; pos > 0; pos -= 1 ) {
    myservo2.write( pos );
    delay( 15 );
  }
}
