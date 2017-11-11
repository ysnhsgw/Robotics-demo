void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(1000);

  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000);

  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000);
  
}
