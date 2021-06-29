#include <iostream>
#include <vector>
#include <utility>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N, 0);
  for (int i=0; i<N; i++) std::cin >> A[i];
  
  int cnt = 0;
  for (int i=0; i<N; i++) {
    int mini = i;
    for (int j=i; j<N; j++) {
      if (A[mini] > A[j]) mini = j;
    }
    std::swap(A[i], A[mini]);
    if (i != mini) cnt++;
  }
  
  for (int i=0; i<N-1; i++) std::cout << A[i] << ' ';
  std::cout << A[N-1] << std::endl;
  std::cout << cnt << std::endl;
  
  return 0;
}
