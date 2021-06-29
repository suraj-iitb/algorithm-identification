#include <iostream>

#define MAX 100
#define MIN 1

int bubble_sort(int A[MAX], int N) {
  int swap_count = 0;

  bool flag = true;
  while(flag) {
    flag = false;
    for (int j = N - 1; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        flag = true;
        swap_count++;
      }
    }
  }

  return swap_count;
}

int main() {
  int N;
  std::cin >> N;
  int A[MAX];
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  int swap_count = bubble_sort(A, N);

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      std::cout << " ";
    }
    std::cout << A[i];
  }
  std::cout << std::endl;

  std::cout << swap_count << std::endl;
  return 0;
}
