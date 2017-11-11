#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pwm.begin();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
  servo_write(0,70);
  servo_write(1,70);
}

void loop() {
  int vol1;
  int vol2;
  
  vol1 = digitalRead(14);
  vol2 = digitalRead(15);
  
  //0番ピンのサーボに角度10度を指示
  if(vol1 == LOW){
    servo_write(0,180);
  }else{
    servo_write(0,0);
  }
  delay(10);
  
  if(vol2 == LOW){
    servo_write(1,180);
  }else{
    servo_write(1,0);
  }
  delay(500);
}

void servo_write(int n, int ang){ //動かすサーボと角度を引数に持つ
  ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); //角度（0～180）をPWMのパルス幅（150～600）へ変換
  pwm.setPWM(n, 0, ang);
}

