int ledPin = 13;

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  randomSeed(analogRead(0));
}

void loop() {
  
  if(Serial.available() > 0){

    String info;
    info = Serial.readStringUntil('\n');

    if(info.equals("TEST")){
     
      long randNumber = random(300);
      Serial.print("#PressureSensor:");
      Serial.print(randNumber);
      
      randNumber = random(300);
      Serial.print(",WeightSensor:");
      Serial.print(randNumber);
      Serial.print("~");
    }

    else if(info.equals("ON")){
      digitalWrite(ledPin, HIGH);
      Serial.print("LED is ON");
    }
    
    else if(info.equals("OFF")){
      digitalWrite(ledPin, LOW);
      Serial.print("LED is OFF");
    }
    else{

      Serial.print("Unknown Command");
    }
  }
}
