#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)

//ボタンのピン配置設定
const int button1 = A0;
const int button2 = A1;

//プッシュボタンが押されてるか押されてないかの読み取りに使う変数
int button1State = 0;
int button2State = 0;

//サーボのオブジェクトを作る
Servo servo1;
Servo servo2;

//サーボの回る回転角度を決める
int flag = 0;
int val = 0;

void setup() {
  //ボタンの初期化
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  //サーボのピンの割り当て
  servo1.attach(0);
  servo2.attach(1);

  //サーボの初期の角度をflagに設定しておく
  servo1.write(flag);
  servo2.write(flag);
  delay(100);
}


void loop() {
  //ボタン1とボタン2の状態の読み取り．スイッチが押される=0，スイッチが押されない=1
  button1State = digitalRead(button1);
  button2Stete = digitalRead(button2);

  if(button1State == HIGH){
    for(val=val:val<=90;val++){
      //サーボを90度回す
      servo1.write(val);
      delay(10);
      button1State = digital
  }
  else{
    //サーボを止める
    servo1.write(flag);
    delay(10);
  }

  delay(100)
  
  //0番ピンのサーボに角度10度を指示
  if(button2State == HIGH){
    servo_write(0,180);
  }else{
    servo_write(0,0);
  }
  delay(500);
}

