#include <iostream>
#include <vector>

void print_vec(const std::vector<int> vec, char sep) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec.at(i);
    if (i < vec.size() - 1) std::cout << sep;
  }
  std::cout << std::endl;
}

void insertion_sort(std::vector<int>* pVec) {
  std::vector<int>& vec(*pVec);

  int n = vec.size();
  for (int i = 1; i < n; i++) {
    print_vec(vec, ' ');
    int val = vec.at(i);

    int j = i - 1;
    for (; j >= 0; j--) {
      if (vec.at(j) > val) {
        vec.at(j + 1) = vec.at(j);
      }
      else {
        break;
      }
    }
    vec.at(j + 1) = val;
  }
  print_vec(vec, ' ');
}

int main(void) {

  int n;
  std::cin >> n;
  std::vector<int> vals;
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    vals.push_back(val);
  }

  insertion_sort(&vals);

  return 0;
}
