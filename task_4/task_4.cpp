#include <iostream>
#include <vector>
#include <string>

int main() {

  int n, k;
  std::string s;

  std::cin >> n >> k;

  std::vector<int> permutation(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> permutation[i];
    --permutation[i];
  }
  std::cin >> s;

  std::string res(n, ' ');
  std::vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      // Находим цикл
      std::vector<int> cycle;
      int cur = i;
      while (!visited[cur]) {
        visited[cur] = true;
        cycle.push_back(cur);
        cur = permutation[cur];
      }

      // Восстанавливаем символы
      int len = cycle.size();
      int shift = k % len;

      for (int j = 0; j < len; j++) {
        res[cycle[j]] = s[cycle[(j - shift + len) % len]];
      }
    }
  }
  std::cout << res << "\n";
}
