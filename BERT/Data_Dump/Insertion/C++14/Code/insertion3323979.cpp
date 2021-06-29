#include <iostream>
#include <vector>

void println(std::vector<int> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i != vec.size() - 1) {
      std::cout << ' ';
    } else {
      std::cout << std::endl;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> vec;
  while (n-- > 0) {
    int buf;
    std::cin >> buf;
    vec.push_back(buf);
  }

  println(vec);
  for (int i = 1; i < vec.size(); i++) {
    int key = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = key;
    println(vec);
  }
  return 0;
}

