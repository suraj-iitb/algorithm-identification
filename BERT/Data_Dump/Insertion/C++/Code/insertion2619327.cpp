#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  if(!v.empty()) {
    std::copy(v.begin(), v.end() - 1, std::ostream_iterator<T>(out, " "));
    out << v.back();
  } else {
    out << "";
  }
  return out;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> xs;
  int x;
  for(int i = 0; i != n; ++i) {
    std::cin >> x;
    xs.push_back(x);
  }

  std::cout << xs << std::endl;

  for(int i = 1; i < n; ++i) {
    int key = xs.at(i);
    int j = i - 1;
    while(j >= 0 && xs.at(j) > key) {
      std::swap(xs.at(j), xs.at(j + 1));
      --j;
    }
    std::cout << xs << std::endl;
  }

  return 0;
}
