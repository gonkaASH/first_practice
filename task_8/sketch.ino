#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(100);
  pixels.show();
}

// Наша математическая функция "змейки"
int getLedIndex(int x, int y) {
  if (x < 0 || x > 7 || y < 0 || y > 7) return -1; 
  if (y % 2 == 0) {
    return (y * 8) + 7 - x;
  } else {
    return (y * 8) + x;
  }
}

// Функция-обертка для рисования
void drawPixel(int x, int y, uint32_t color) {
  int index = getLedIndex(x, y);
  if (index != -1) {
    pixels.setPixelColor(index, color);
  }
}

// Функция для отрисовки картинки на матрице
void drawFrame(uint8_t frame[8][8], uint32_t color) {
  pixels.clear();
  for(int y = 0; y < 8; y++) {
    for(int x = 0; x < 8; x++) {
      if (frame[y][x] == 1) { 
        drawPixel(x, y, color); // Зажигаем только те, где прописана единица
      }
    }
  }
  pixels.show(); // Отправляем данные на матрицу
}

uint8_t frame1[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

uint8_t frame2[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

uint8_t frame3[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0}
};

uint8_t frame4[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1}
};

uint8_t frame5[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1}
};

uint8_t heart[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

void loop() {
  //1. Анимация "Расходящиеся квадраты"
  drawFrame(frame1, pixels.Color(0, 0, 255));
  delay(500);

  drawFrame(frame2, pixels.Color(0, 0, 255));
  delay(500);

  drawFrame(frame3, pixels.Color(0, 0, 255));
  delay(500);

  drawFrame(frame4, pixels.Color(0, 0, 255));
  delay(500);

  drawFrame(frame5, pixels.Color(0, 0, 255));
  delay(500);

  // 2. Анимация "Змейка"
  // По очереди зажигаем светодиоды зеленым цветом
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(30);
  }

  delay(500); // Небольшая пауза

  // Так же по очереди их гасим
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Выключить цвет
    pixels.show();
    delay(30);
  }

  delay(500);

  //3. Анимация "Сердце"

  for (int i = 0; i < 10; ++i) {
    drawFrame(heart, pixels.Color(255, 0, 0));
    delay(500);
    drawFrame(heart, pixels.Color(125, 0, 0));
    delay(500);
  }
}