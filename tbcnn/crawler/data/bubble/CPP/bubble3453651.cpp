#include <iostream>
#include <vector>
#include <utility>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N, 0);
  for (int i=0; i<N; i++) std::cin >> A[i];
  
  int cnt = 0;
  for (int i=1; i<N; i++) {
    int j = i;
    while(A[j] < A[j-1]) {
      std::swap(A[j], A[j-1]);
      cnt++;
      j--;
    }
  }
  
  for (int i=0; i<N-1; i++) std::cout << A[i] << ' ';
  std::cout << A[N-1] << std::endl;
  std::cout << cnt << std::endl;
  
  return 0;
}
