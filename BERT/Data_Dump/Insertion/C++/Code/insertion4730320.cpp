#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  int A[N];
  int Arry[N];

  for (int ii = 0; ii < N; ii++) {
    std::cin >> A[ii];  // input array
  }

  for (int i = 0; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    for (int p_index = 0; p_index < N; p_index++) {
      std::cout << (p_index == 0 ? "" : " ") << A[p_index];  // print array
    }
    std::cout << std::endl;
  }
  return 0;
}
