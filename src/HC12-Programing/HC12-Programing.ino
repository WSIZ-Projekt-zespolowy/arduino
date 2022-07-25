//HC-12 AT Commander
//Autor Tom Heylen tomtomheylen.com
//The HC-12 commander mode runs at baud rate 9600


// write to terminal on PC: AT+DEFAULT

void setup() {
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  Serial1.begin(9600);
}

void loop(){
  if (Serial1.available()){
    Serial.write(Serial1.read());
  }
  if (Serial.available()){
    Serial1.write(Serial.read());
  }
}
