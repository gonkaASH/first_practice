#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUMPIXELS 64 //8x8 светодиодов

// Инициализируем матрицу
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(40); // Яркость
}

void loop() {
  // По очереди зажигаем светодиоды зеленым цветом
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Зеленый
    pixels.show();
    delay(30); // Скорость бега огонька (в миллисекундах)
  }

  delay(500); // Небольшая пауза

  // Так же по очереди их гасим
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Выключить цвет
    pixels.show();
    delay(30);
  }

  delay(500);
}