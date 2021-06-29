#include <iostream>
#include <ostream>
#include <vector>

const int index_max_size = 500000;
int       left_tmp[index_max_size / 2 + 2];
int       right_tmp[index_max_size / 2 + 2];
const int SEN = 2000000000;//番兵
int cnt;

void merge_sort(int* data, int n, int left, int right);
void merge(int* data, int n, int left, int mid, int right);

int main(int argc, char const* argv[]) {
  int n;
  int data[index_max_size];
  cnt = 0;

  std::cin >> n;

  for (int i = 0; i < n; i++) { std::cin >> data[i]; }

  merge_sort(&(data[0]),  n, 0, n);

  for (int i = 0; i < n; i++) {
    std::cout << data[i];
    if (i != n - 1) { std::cout << " "; }
  }

  std::cout << std::endl;
  std::cout << cnt << std::endl;

  return 0;
}

void merge_sort(int* data,  int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(data,  n, left, mid);
    merge_sort(data, n, mid, right);
    merge(data,  n, left, mid, right);
  } 
};

void merge(int* data,  int n, int left, int mid, int right) {
  int       n1 = mid - left;
  int       n2 = right - mid;

  for (int i = 0; i < n1; i++) { left_tmp[i] = data[left + i]; }
  for (int i = 0; i < n2; i++) { right_tmp[i] = data[mid + i]; }

  left_tmp[n1] =  SEN;
  right_tmp[n2] = SEN;

  int i1 = 0;
  int i2 = 0;
  for (int i = left; i < right; i++) {
    cnt++;
    if (left_tmp[i1] <= right_tmp[i2]) {
      data[i] = left_tmp[i1++];
    } else {
      data[i] = right_tmp[i2++];
    }
  }
};

