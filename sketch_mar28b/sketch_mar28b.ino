#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // this is the 'maximum' pulse length count (out of 4096)
#define UD 30
#define RL 50
int aa = 120;
int bb = 60;
int cc = 120;
int dd = 60;
int aaa = 70;
int bbb = 100;
int ccc = 65;
int ddd = 130;

/******************************************* 
 * 全くC++の意味がないあほみたいなコードです 
 */
 
void setup() {
  pwm.begin();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
  servo_write(0,aa); //down120 up70
  servo_write(5,bb); //down60
  servo_write(8,cc); //down100
  servo_write(13,dd); //down70

  servo_write(1,aaa+10);
  servo_write(4,bbb-10);
  servo_write(9,ccc+10);
  servo_write(12,ddd-10);
  delay(100);
}

void loop() {
  up(0);
  down(0);
  up(2);
  down(2);
  up(1);
  down(1);
  up(3);
  down(3);
  //exit(0);
}

void servo_write(int n, int ang){ //動かすサーボと角度を引数に持つ
  ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); //角度（0～180）をPWMのパルス幅（150～600）へ変換
  pwm.setPWM(n, 0, ang);
}

void walk(int n, int arg){
  if(n==0){
    for(int i=0; i<arg; i++){
      servo_write(0,aa-UD);
      servo_write(1,aaa+RL);
      servo_write(8,cc-UD);
      servo_write(9,ccc+RL);
      delay(200);
      servo_write(0,aa);
      servo_write(8,cc);
      delay(200);
      servo_write(1,aaa);
      servo_write(9,ccc);
    }
  }else if(n==1){
    for(int i=0; i<arg; i++){
      servo_write(5,bb+UD);
      servo_write(4,bbb-RL);
      servo_write(13,dd+UD);
      servo_write(12,ddd-RL);
      delay(200);
      servo_write(5,bb);
      servo_write(13,dd);
      delay(200);
      servo_write(4,bbb);
      servo_write(12,ddd);
    }
  }
}

void up(int num){
  if(num==0){
    servo_write(0,aa-UD);
    delay(200);
  }else if(num==1){
    servo_write(5,bb+UD);
    delay(200);
  }else if(num==2){
    servo_write(8,cc-UD);
    delay(200);
  }else if(num==3){
    servo_write(13,dd+UD);
    delay(200);
  }
}
void down(int num){
  if(num==0){
    servo_write(0,aa);
    delay(200);
  }else if(num==1){
    servo_write(5,bb);
    delay(200);
  }else if(num==2){
    servo_write(8,cc);
    delay(200);
  }else if(num==3){
    servo_write(13,dd);
    delay(200);
  }
}
// 0or1対の足をnum歩動かす
void leg(String arg, int num){
  // 1,4,9,12
  if(arg=="A"){
    for(int i=0; i<num; i++){
      servo_write(0,aa-UD);
      delay(200);
      servo_write(0,aa);
    }
  }else if(arg=="B"){
    for(int i=0; i<num; i++){
      servo_write(8,bb+UD);
      delay(200);
      servo_write(8,bb);
    }
  }else if(arg=="C"){
    for(int i=0; i<num; i++){
      servo_write(5,cc-UD);
      delay(200);
      servo_write(5,cc);
    }
  }else if(arg=="D"){
    for(int i=0; i<num; i++){
      servo_write(13,dd+UD);
      delay(200);
      servo_write(13,dd);
    }
  }
}

