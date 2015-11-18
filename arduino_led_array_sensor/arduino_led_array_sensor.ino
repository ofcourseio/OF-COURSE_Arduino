const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
const int buttonPin = 13;
const int sensorPin = A0;

void setup() {

  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  int buttonStatus = digitalRead(buttonPin);
  int sensorVal = analogRead(sensorPin);
  int ledLight = map(sensorVal, 0, 1023, 255, 0);
  Serial.println(ledLight);

  for (int i = 0; i < 50; i++) {

    if (buttonStatus == HIGH) {
      
      sensorVal = analogRead(sensorPin);
      ledLight = map(sensorVal, 0, 1023, 255, 0);
      Serial.println(ledLight);
      analogWrite(ledPin1, ledLight);
      analogWrite(ledPin2, 0);
      analogWrite(ledPin3, 0);
      delay(60);

      sensorVal = analogRead(sensorPin);
      ledLight = map(sensorVal, 0, 1023, 255, 0);
      Serial.println(ledLight);
      analogWrite(ledPin1, 0);
      analogWrite(ledPin2, ledLight);
      analogWrite(ledPin3, 0);
      delay(60);

      sensorVal = analogRead(sensorPin);
      ledLight = map(sensorVal, 0, 1023, 255, 0);
      Serial.println(ledLight);
      analogWrite(ledPin1, 0);
      analogWrite(ledPin2, 0);
      analogWrite(ledPin3, ledLight);
      delay(60);

      sensorVal = analogRead(sensorPin);
      ledLight = map(sensorVal, 0, 1023, 255, 0);
      Serial.println(ledLight);
      analogWrite(ledPin1, 0);
      analogWrite(ledPin2, 0);
      analogWrite(ledPin3, 0);

    }
  }



}
