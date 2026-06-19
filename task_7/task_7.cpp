#include <iostream>
#include <string>

int main() {
  std::string number;
  std::cin >> number;

  bool flag = true; //флаг "номер корректный"
  for (int i = 0; i < 6; ++i) {
    char ch = number[i];
    //Проверяем места, где должны быть цифры
    if (i >= 1 && i <= 3) {
      if (!(ch <= '9' && ch >= '0')) {
        flag = false;
      }
    //Проверяем места, где должны быть буквы
    } else {
      if (!(ch <= 'Z' && ch >= 'A')) {
        flag = false;
      }
    }
  }
  if (flag) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}
