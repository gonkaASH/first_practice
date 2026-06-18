#include <iostream>
#include <vector>

int main() {

  int h, w, i, j;
  std::cin >> h >> w;
  std::vector<std::vector<int>> matrix(h, std::vector<int>(w, 0));

  for (i = 0; i < h; ++i) {
    for (j = 0; j < w; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int up = h;
  int left = w;
  int down = -1;
  int right = -1;

  for (i = 0; i < h; ++i) {
    for (j = 0; j < w; ++j) {
      if (matrix[i][j] == 1) {
        if (i < up) {
          up = i;
        }
        if (j > right) {
          right = j;
        }
        if (i > down) {
          down = i;
        }
        if (j < left) {
          left = j;
        }
      }
    }
  }
  left -= 1;
  right += 1;
  up -= 1;
  down += 1;
  std::cout << up << " " << left << " " << down << " " << right << "\n";
}
