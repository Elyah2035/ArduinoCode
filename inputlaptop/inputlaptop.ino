int inputblinknumb = 0;
bool doneWithMyLife=false;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
bling();

}

void bling() {
  if (Serial.available() > 0) {
    
      inputblinknumb = Serial.read();
    
    if (inputblinknumb > 47 && inputblinknumb < 57 && inputblinknumb != 0) {
      
      inputblinknumb = inputblinknumb - 48;
      Serial.print(inputblinknumb);
      for (int i = 0; i < inputblinknumb; i++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);

      }   

    } 
  }
      while(Serial.available() > 0)   {
        Serial.read();
      }
       
}


