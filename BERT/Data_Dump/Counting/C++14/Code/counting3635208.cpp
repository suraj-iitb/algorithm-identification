#include <array>
#include <iostream>
#include <vector>

void printVector(std::vector<int> &a) {
  std::size_t n = a.size();
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::cout << a.at(i);
    if (i < n - 1)
      std::cout << " ";
    else
      std::cout << std::endl;
  }
}

void countingSort(std::vector<int> &a, std::vector<int> &b, int k) {
  int n = a.size();
  std::vector<int> c(k + 1, 0);

  // C[i]にiの出現数を記録する
  for (int i = 0; i < n; ++i) {
    c.at(a.at(i))++;
  }

  // c[i]にi以下の数を出現数を記録する
  for (int i = 1; i <= k; ++i) {
    c.at(i) = c.at(i) + c.at(i - 1);
  }

  for (int i = n - 1; i >= 0; --i) {
    b.at(c.at(a.at(i)) - 1) = a.at(i);
    c.at(a.at(i))--;
  }
  printVector(b);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 0), b(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a.at(i);
  }

  countingSort(a, b, 10000);
}

