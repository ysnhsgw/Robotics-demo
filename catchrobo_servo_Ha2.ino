#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
    
  pwm.begin();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
  servo_write(0,70);
  servo_write(1,70);
  servo_write(2,70);
  servo_write(3,70);
}

void loop() {
  int vol1;
  int vol2;
  int vol3;
  int vol4;
  
  vol1 = digitalRead(14);
  vol2 = digitalRead(15);
  vol3 = digitalRead(17);
  vol4 = digitalRead(18);

//箱を落とす両側サーボの回転(0度~180度)
  if(vol1 == LOW && vol2 == LOW){
   servo_write(0,0);
   servo_write(1,180);
  }else if(vol1 == LOW){
    servo_write(0,180);
  }else if(vol2 == LOW){
    servo_write(1,0);
  }else{
    delay(10);
  }
  delay(500);

//箱押さえと箱閉じに使うサーボの回転
  if(vol3 == LOW && vol4 == LOW){
   servo_write(2,0);
   servo_write(3,180);
  //0番ピンのサーボに角度10度を指示
  }else if(vol3 == LOW){
    servo_write(2,180);
  }else if(vol4 == LOW){
    servo_write(3,0);
  }else{
    delay(10);
  }
  delay(500);
}

void servo_write(int n, int ang){ 
  ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); //角度（0～180）をPWMのパルス幅（150～600）へ変換
  pwm.setPWM(n, 0, ang);
}

