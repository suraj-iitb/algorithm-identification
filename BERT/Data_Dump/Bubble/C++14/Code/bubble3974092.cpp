#include <iostream>
#include <vector>

int main() {
  int n, temp;
  std::vector<int> A;
  
  std::cin >> n;
  
  for (auto i=0; i<n; ++i) {
    std::cin >> temp;
    A.push_back(temp);
  }
  
  bool flag = true;
  auto counter = 0;
  
  while (flag) {
    flag = false;
    for (auto i=n-1; i>0; --i) {
      if (A.at(i) < A.at(i-1)) {
        std::swap(A.at(i), A.at(i-1));
        flag = true;
        ++counter;
      }
    }
  }
  for (auto i=0; i<n-1; ++i)
    std::cout << A.at(i) << " ";
  
  std::cout << A.back() << std::endl << counter << std::endl;
}
