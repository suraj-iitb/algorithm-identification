#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N, 0);
  for (int i=0; i<N; i++) {
    std::cin >> A[i];
  }
  for (int i=0; i<N-1; i++) {
    std::cout << A[i] << ' ';
  }
  std::cout << A[N-1] << std::endl;
  
  for (int i=1; i<N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for (int i=0; i<N-1; i++) {
      std::cout << A[i] << ' ';
    }
    std::cout << A[N-1] << std::endl;
  }
  
  return 0;
}
