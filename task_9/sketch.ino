const int redLedPin = 9;
const int greenLedPin = 5;
const int sensorPin = A0;

bool isDoorOpen = false;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  // Инициализация последовательного порта для вывода сообщений
  Serial.begin(9600); 

  // По умолчанию горит красный светодиод (дверь закрыта)
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}

void loop() {
  // Чтение значения с фоторезистора
  int sensorValue = analogRead(sensorPin);

  if (sensorValue > 512) {
    if (!isDoorOpen) {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      Serial.println("Двери открываются!");

      isDoorOpen = true;

      delay(3000); //Перерыв 3 секунды после открытия двери
    } 
  } else {
    if (isDoorOpen) {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      Serial.println("Двери закрываются!");

      isDoorOpen = false;
    } 
  }
  
  delay(100); 
}