#include <iostream>
#include <vector>

class FenwickTree {
  std::vector<int> data_;
  int size_ = 0;

  // Сумма элементов от 1 до i
  int sum(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += data_[i];
    }
    return sum;
  }

 public:
  // Конструктор
  FenwickTree(int size) : size_(size) {
    data_ = std::vector<int>(size + 1, 0);
  }

  // Добавление значения в массив
  void add(int i, int value) {
    for (; i <= size_; i += i & -i) {
      data_[i] += value;
    }
  }

  // Сумма от l до r включительно
  int range_sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

int main() {

  int n, m;
  std::cin >> n >> m;

  FenwickTree tree = n;
  int request, first_num, second_num;
  for (int i; i < m; ++i) {
    std::cin >> request >> first_num >> second_num;
    if (request == 1) {
      tree.add(first_num, second_num);
    } else {
      std::cout << tree.range_sum(first_num, second_num) << "\n";
    }
  }
}
