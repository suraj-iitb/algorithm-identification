#include <array>
#include <iostream>
#include <string>

int main() {
  uint32_t N = 0;
  std::cin >> N;

  std::array<uint32_t, 100> A;
  for (size_t i = 0; i < N; i++) std::cin >> A[i];

  for (size_t i = 0; i < N; i++) {
    uint32_t a_i = A[i];
    for (size_t j = 0; j < i; j++) {
      if (A[(i - 1) - j] < a_i) break;

      A[(i - 1) - j + 1] = A[(i - 1) - j];
      A[(i - 1) - j] = a_i;
    }

    for (size_t k = 0; k < N - 1; k++) std::cout << A[k] << " ";
    std::cout << A[N - 1] << std::endl;
  }

  return 0;
}
