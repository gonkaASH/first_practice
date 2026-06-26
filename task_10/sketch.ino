#include <Servo.h>

#define SERVO_PIN 3

Servo myServo; //Создаём объект сервопривода

// Переменная для хранения текущего угла
int currentAngle = 0;

void setup() {
  // Инициализируем последовательный порт
  Serial.begin(9600);
  
  // Подключаем сервопривод к пину
  myServo.attach(SERVO_PIN);
  
  // Устанавливаем в начальное положение
  myServo.write(currentAngle);
  Serial.println("Введите угол от 0 до 180 градусов:");
}

void loop() {
  // Ожидания ввода данных в последовательный порт
  if (Serial.available() > 0) {
    
    // Чтение строки
    String inputString = Serial.readStringUntil('\n');
    
    // Удаление случайных пробелов
    inputString.trim();
    
    // Проверяем строку на корректность
    if (isValidNumber(inputString)) {
      int targetAngle = inputString.toInt();
      if (targetAngle >= 0 && targetAngle <= 180) {
        if (targetAngle != currentAngle) {
          Serial.print("Перемещаю сервопривод в положение: ");
          Serial.print(targetAngle);
          Serial.println(" град.");
          
          moveServoSmoothly(currentAngle, targetAngle);
          
          // Запоминаем новое текущее положение
          currentAngle = targetAngle; 
        } else {
          Serial.println("Сервопривод уже находится в этом положении.");
        }
        
      } else {
        Serial.println("Ошибка! Диапазон угла должен быть строго от 0 до 180.");
      }
      
    } else {
      Serial.println("Ошибка! Введены некорректные данные. Допускаются только числа.");
    }
  }
}

// Проверка на то, что строка состоит только из цифр
bool isValidNumber(String& str) {
  if (str.length() == 0)  {
    return false;
  }

  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str[i])) {
      return false;
    }
  }
  return true;
}

// Функция для плавного перемещения
void moveServoSmoothly(int& fromAngle, int& toAngle) {
  if (fromAngle < toAngle) {
    // Если новый угол больше текущего — плавно увеличиваем
    for (int pos = fromAngle; pos <= toAngle; pos++) {
      myServo.write(pos);
      delay(20);
    }
  } else {
    // Если новый угол меньше текущего — плавно уменьшаем
    for (int pos = fromAngle; pos >= toAngle; pos--) {
      myServo.write(pos);
      delay(20);
    }
  }
}
