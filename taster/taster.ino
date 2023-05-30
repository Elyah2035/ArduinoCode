void setup() {
  pinMode(3, INPUT);
}
int onOFF;
void loop() {
  if(digitalRead(3) == true){
    if(onOFF==1){
      onOFF = 0;
      delay(100);
    }
    if(onOFF==0){
      onOFF = 1;
      delay(100);
    }
  }
  if(onOFF==1){
    digitalWrite(LED_BUILTIN ,HIGH);
  }
  if(onOFF==0){
    digitalWrite(LED_BUILTIN ,LOW);
  }
}