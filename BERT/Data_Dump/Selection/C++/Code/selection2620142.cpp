#include <algorithm>
#include <iostream>
#include <iterator>
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

int selection_sort(std::vector<int> &xs) {
  int len = xs.size();
  int cnt_swap = 0;

  for(int i = 0; i < len; ++i) {
    int minj = i;
    for(int j = i; j < len; ++j) {
      if(xs[j] < xs[minj])
        minj = j;
    }
    if(i != minj) {
      std::swap(xs[i], xs[minj]);
      cnt_swap++;
    }
  }

  return cnt_swap;
}

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> xs;
  int x;
  for(int i = 0; i < n; ++i) {
    std::cin >> x;
    xs.push_back(x);
  }

  int cnt = selection_sort(xs);

  std::cout << xs << std::endl;
  std::cout << cnt << std::endl;

  return 0;
}
