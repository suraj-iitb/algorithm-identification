#include <array>
#include <iostream>

int main() {
  uint32_t N = 0;
  std::array<uint32_t, 100> A;
  std::cin >> N;
  for (size_t i = 0; i < N; i++) std::cin >> A[i];

  uint32_t count = 0;
  for (size_t i = 0; i < N - 1; i++) {
    uint32_t min_index = i;
    for (size_t j = i + 1; j < N; j++) {
      if (A[min_index] > A[j]) min_index = j;
    }
    if (min_index != i) {
      uint32_t temp = A[i];
      A[i] = A[min_index];
      A[min_index] = temp;
      count++;
    }
  }

  for (uint32_t i = 0; i < N - 1; i++) std::cout << A[i] << " ";
  std::cout << A[N - 1] << std::endl;
  std::cout << count << std::endl;

  return 0;
}
