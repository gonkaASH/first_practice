#include <iostream>
#include <vector>

// Вычисление обратной перестановки (для декодирования)
std::vector<int> Inverse(std::vector<int>& p) {
  int n = p.size();
  std::vector<int> inv_p = p;
  for (int i = 0; i < p.size(); ++i) {
    inv_p[p[i] - 1] = i + 1;
  }
  return inv_p;
}

//Применение перестановки к строке
std::string Permutation(std::string& s, std::vector<int>& p) {
  int n = p.size();
  std::string res = s;
  for (int i = 0; i < n; ++i) {
    res[i] = s[p[i] - 1];
  }
  return res;
}

int main() {

  int n, k, a;
  std::vector<int> permutation;
  std::string s;

  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    permutation.push_back(a);
  }
  std::cin >> s;

  std::vector<int> inv_permutation = Inverse(permutation);

  //k раз применяем обратную перестановку для декодировки
  for (int i = 0; i < k; ++i) {
    s = Permutation(s, inv_permutation);
  }

  std::cout << s << "\n";
}
