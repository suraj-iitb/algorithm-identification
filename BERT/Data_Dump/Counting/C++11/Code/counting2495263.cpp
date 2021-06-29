#include <iostream>
#include <vector>

int N;

void countingSort(std::vector<int>& A, std::vector<int>* B, int k) {
  std::vector<int> C(k + 1, 0);

  for (int j = 0; j < N; ++j)
    C[A[j]]++;

  for (int i = 1 ; i <= k; ++i)
    C[i] = C[i] + C[i-1];

  for (int j = N - 1; j >= 0; --j) {
    (*B)[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main() {
  std::cin >> N;
  std::vector<int> A;
  int max = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    max = (a > max) ? a : max;
    A.push_back(a);
  }
  std::vector<int> B(N + 1);
  countingSort(A, &B, max);
  for (int i = 1; i <= N; ++i) {
    std::cout << B[i] << (i == N ? "\n" : " ");
  }
  return 0;
}
