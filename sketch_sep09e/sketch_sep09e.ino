#include <Servo.h>
Servo servo;


void setup() {
  servo.attach(9); //D9ピンをサーボの信号線として設定
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90); //サーボの角度を90度に設定
  delay(1000);
  servo.write(0);  //サーボの角度を0度に設定
  delay(1000);
}
