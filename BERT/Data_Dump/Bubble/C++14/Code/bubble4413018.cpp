#include <array>
#include <iostream>

int main() {
  uint32_t N = 0;
  std::array<uint32_t, 100> A;
  std::cin >> N;
  for (size_t i = 0; i < N; i++) std::cin >> A[i];

  uint32_t count = 0, prev_count = 0;
  for (size_t i = 0; i < N - 1; i++) {
    prev_count = count;
    for (size_t j = 0; j < N - 1 - i; j++) {
      if (A[N - 1 - j] < A[N - 2 - j]) {
        uint32_t temp = A[N - 1 - j];
        A[N - 1 - j] = A[N - 2 - j];
        A[N - 2 - j] = temp;
        count++;
      }
    }
    if (prev_count == count) break;
  }

  for (uint32_t i = 0; i < N - 1; i++) std::cout << A[i] << " ";
  std::cout << A[N - 1] << std::endl;
  std::cout << count << std::endl;

  return 0;
}
