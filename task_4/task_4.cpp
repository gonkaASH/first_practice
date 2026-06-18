#include <iostream>
#include <vector>

//Вычисление обратной перестановки (для декодирования)
std::vector<int> Inverse(std::vector<int>& p) {
  std::vector<int> inv_p = p;
  for (int i = 0; i < p.size(); ++i) {
    inv_p[p[i] - 1] = i + 1;
  }
  return inv_p;
}

int main() {

  int n, a;
  std::cin >> n;
  std::vector<int> permutation;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    permutation.push_back(a);
  }
  std::vector<int> inv_permutation = Inverse(permutation);
  for (int i = 0; i < n; ++i) {
    std::cout << inv_permutation[i] << " ";
  }
}
