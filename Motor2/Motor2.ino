void signal1(int value) {
  switch (value) {
    case 0:
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      break;
    case 1:
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
  }
}

void signal2(int value) {
  switch (value) {
    case 0:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;
    case 1:
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      break;
  }
}
 
void forward() {
  signal1(1);
  signal2(0);
}

void back() {
  signal1(0);
  signal2(1);
}

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  forward();
  delay(1000);
  back();
  delay(1000);
}


