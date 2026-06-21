#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Считывание входных данных
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> triangle(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cin >> triangle[i][j];
    }
  }

  // Подсчёт минимального времени спуска через динамическое программирование
  std::vector<std::vector<int>> dp = triangle;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  // Вывод
  std::cout << dp[0][0] << "\n";

  int i = 0;
  int j = 0;
  std::cout << triangle[i][j] << " ";

  // Восстановление пути
  while (i < (n - 1)) {
    if (dp[i + 1][j] <= dp[i + 1][j + 1]) {
      ++i;
      std::cout << triangle[i][j] << " ";
    } else {
      ++i;
      ++j;
      std::cout << triangle[i][j] << " ";
    }
  }
}
