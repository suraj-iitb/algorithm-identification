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
  
  auto counter = 0;
  
  for (auto i=0; i<n-1; ++i) {
    int min_idx = i;
    for (auto j=i; j<n; ++j) {
      if (A.at(min_idx) > A.at(j)) {
        min_idx = j;
      }
    }
    if (i !=  min_idx) {
      std::swap(A.at(i), A.at(min_idx));
      ++counter;
    }
  }

  for (auto i=0; i<n-1; ++i)
    std::cout << A.at(i) << " ";
  
  std::cout << A.back() << std::endl << counter << std::endl;
}
