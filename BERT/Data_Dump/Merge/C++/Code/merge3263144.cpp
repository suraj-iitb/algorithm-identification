#include <iostream>
#include <vector>

int count = 0;

void merge(std::vector<int> &a, int left, int mid, int right) {

  const int sentinel = 1000000000;

  int n1 = mid - left;
  int n2 = right - mid;

  std::vector<int> l(n1+1);
  std::vector<int> r(n2+1);

  for (int i = 0; i < n1; i++) {
    l[i] = a[left+i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = a[mid+i];
  }
  l[n1] = r[n2] = sentinel;

  int i = 0, j = 0;

  for (int k = left; k < right; k++) {
    count++;
    if (l[i] < r[j]) {
      a[k] = l[i];
      i++;
    } else {
      a[k] = r[j];
      j++;
    }
  }
}

void mergeSort(std::vector<int> &a, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main() {

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  mergeSort(a, 0, n);

  for (int i = 0; i < n; i++) {
    if (i) {
      std::cout << " ";
    }
    std::cout << a[i];
  }
  std::cout << std::endl;
  std::cout << count << std::endl;

  return 0;

}

