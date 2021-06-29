#include <iostream>
#include <vector>

const int INF = 1e9 + 1;

void printVector(const std::vector<int> &a) {
  std::size_t n = a.size();
  for (std::size_t i = 0; i < n; i++) {
    std::cout << a[i];
    if (i < n - 1)
      std::cout << " ";
    else
      std::cout << std::endl;
  }
}

int merge(std::vector<int> &a, int left, int mid, int right) {
  int nL = mid - left, nR = right - mid;
  std::vector<int> L(nL + 1, INF), R(nR + 1, INF);
  for (int i = 0; i < nL; i++) {
    L[i] = a[left + i];
  }
  for (int i = 0; i < nR; i++) {
    R[i] = a[mid + i];
  }

  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      ++i;
    } else {
      a[k] = R[j];
      ++j;
    }
  }
  return i + j;
}

int mergeSort(std::vector<int> &a, int left, int right) {
  if (left + 1 < right) {
    int c;
    int mid = (left + right) / 2;
    c = mergeSort(a, left, mid);
    c += mergeSort(a, mid, right);
    c += merge(a, left, mid, right);
    return c;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int count = mergeSort(a, 0, n);
  printVector(a);
  std::cout << count << std::endl;
}

