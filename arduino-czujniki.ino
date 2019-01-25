int cm = 0;
int sensorPin = 0;
long read(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

void loop()
{
  cm = 0.01723 * read(2,2);
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
 	voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;
  if (cm < 25 && temperatureC > 80){
  	Serial.print(cm);
  	Serial.println("cm");
    Serial.println("Danger area, stay back!");
    Serial.print(temperatureC); Serial.println(" degrees C");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  else{
    Serial.print(cm);
  	Serial.println("cm");
    Serial.print(temperatureC); Serial.println(" degrees C");
    Serial.println("Safe area, you can continue");
    
  }
  delay(1000);
}
