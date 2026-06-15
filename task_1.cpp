#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n;
  std::cin >> n;

  int INF = INT_MAX;

  std::vector<std::vector<int>> triangle(n, std::vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cin >> triangle[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << triangle[i][j] << " ";
    }

    std::cout << std::endl;
  }
}
