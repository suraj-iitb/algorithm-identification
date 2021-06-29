#include <iostream>
#include <vector>

void printVector(const std::vector<int> &A) {
  auto len = A.size();
  for (auto i=0; i<len-1; ++i) {
    std::cout << A.at(i) << " ";
  }
  std::cout << A.back() << std::endl;
}

int main() {
  int n, temp;
  std::vector<int> A;
  
  std::cin >> n;
  
  for (auto i=0; i<n; ++i) {
    std::cin >> temp;
    A.push_back(temp);
  }
  
  printVector(A);
  
  for (auto i=1; i<n; ++i) {
    auto j = i-1;
    auto pivot = A.at(i);
    
    while (j >= 0 && A.at(j) > pivot) {
      A.at(j+1) = A.at(j);
      --j;
    }
    A.at(j+1) = pivot;
    
    printVector(A);
  }
}
