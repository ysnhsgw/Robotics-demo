#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)


void setup() {
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pwm.begin();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
  servo_write(0,10);
  servo_write(1,10);
}

int vol1;
int vol2;

void loop() {
  vol1 == digitalRead(8);
  vol2 == digitalRead(9);
  //0番ピンのサーボに角度10度を指示
  if(vol1 == 0)
    servo_write(0,90);
  else
    servo_write(0,10);
  
  if(vol2 == 0)
  //0番ピンのサーボに角度170度を指示
    servo_write(1,90);
  else
    servo_write(1,10);
  delay(500);
}

void servo_write(int n, int ang){ //動かすサーボと角度を引数に持つ
  ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); //角度（0～180）をPWMのパルス幅（150～600）へ変換
  pwm.setPWM(n, 0, ang);
}
