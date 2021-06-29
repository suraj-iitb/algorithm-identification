#include <array>
#include <iostream>
#include <vector>

uint32_t count = 0;

void merge_sort(uint32_t start, uint32_t end, std::array<uint32_t, 500000>& A) {
  if (end - start == 1) return;
  uint32_t mid = (end + start + 1) / 2;
  merge_sort(start, mid, A);
  merge_sort(mid, end, A);

  std::vector<uint32_t> L(mid - start + 1);
  std::vector<uint32_t> R(end - mid + 1);
  for (uint32_t i = 0; i < mid - start; i++) L[i] = A[start + i];
  for (uint32_t i = 0; i < end - mid; i++) R[i] = A[mid + i];
  L.back() = -1;
  R.back() = -1;

  auto iter_L = L.begin(), iter_R = R.begin();
  for (uint32_t i = 0; i < end - start; i++) {
    if (*iter_L <= *iter_R) {
      A[start + i] = *iter_L;
      iter_L++;
    } else {
      A[start + i] = *iter_R;
      iter_R++;
    }
    count++;
  }

  return;
}

int main() {
  std::array<uint32_t, 500000> A;

  uint32_t n = 0;
  std::cin >> n;
  for (uint32_t i = 0; i < n; i++) std::cin >> A[i];

  merge_sort(0, n, A);
  for (size_t i = 0; i < n - 1; i++) std::cout << A[i] << " ";
  std::cout << A[n - 1] << std::endl;
  std::cout << count << std::endl;

  return 0;
}
