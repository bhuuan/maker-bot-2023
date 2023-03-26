void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  Serial.println("Done Setup");
}

void loop() {
  //Den tin hieu
  if(digitalRead(8) == 1 && digitalRead(9) == 1){
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    Serial.println("Tin hieu 2 den");
    delay(370);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    delay(370);
  } else if(digitalRead(8) == 0 && digitalRead(9) == 0){
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  }
  //Tin hieu re trai
  if(digitalRead(8) == 1 && digitalRead(9) == 0){
    digitalWrite(4, 1);
    Serial.println("Tin hieu re trai");
    delay(370);
    digitalWrite(4, 0);
    delay(370);
  }
  //Tin hieu re phai
  if(digitalRead(9) == 1 && digitalRead(8) == 0){
    digitalWrite(5, 1);
    Serial.println("Tin hieu re phai");
    delay(370);
    digitalWrite(5, 0);
    delay(370);
  }
  delay(50);
}
