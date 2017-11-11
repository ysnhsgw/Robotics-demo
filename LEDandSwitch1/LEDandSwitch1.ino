// LEDがArduino digital port12につながっている
// SWがArduino digital port11につながっている
int ledPin = 12;
int swPin = 11;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);  //LEDのつながっているピンを出力にする
  pinMode(swPin, INPUT);    //スイッチのつながっているピンを入力にする
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(swPin); 
  //スイッチのつながっているピンからデジタルでデータを読み取る．
  //スイッチがONの時，val = 1
  //スイッチがOFFの時，val = 0
  digitalWrite(ledPin, val);
  //LEDのつながっているピンに対して，valの値に従って入力を行う
  //val = 1の時，つまり，スイッチがONの時，LEDもONになって光る
}
