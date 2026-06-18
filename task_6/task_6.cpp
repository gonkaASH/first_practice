#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n, a, b, x, y;
  std::cin >> n;

  std::vector<int> res;

  // Максимальное количество всех пар и пар с микроконтрролеррами типа B
  int sum_pairs, max_pairs_B;

  for (int i = 0; i < n; ++i) {
    sum_pairs = max_pairs_B = 0;
    std::cin >> a >> b >> x >> y;

    max_pairs_B = std::min(b, x);  // Подсчёт числа пар с микроконтроллерами типа B
    b -= max_pairs_B;              // Вычет микроконтроллеров (B), уже использованных
    x -= max_pairs_B;              // Вычет модулей управления (1), уже использованных
    sum_pairs += max_pairs_B;      // Прибавка к общей сумме

    // Формируем пары из оставшихся модулей контроля и микроконтроллеров типа B
    sum_pairs += std::min(x + y, a);

    res.push_back(sum_pairs);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << "\n";
}
