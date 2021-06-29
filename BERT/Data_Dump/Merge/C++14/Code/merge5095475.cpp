#include <iostream>
#include <memory>
#include <cstring>
#include <limits>
using namespace std;

int
merge(int A[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  auto L = make_unique<int[]>(n1 + 1);
  auto R = make_unique<int[]>(n2 + 1);
  memcpy(L.get(), &A[left], sizeof(int) * n1);
  memcpy(R.get(), &A[mid], sizeof(int) * n2);
  L[n1] = R[n2] = numeric_limits<int>::max();

  int i = 0;
  int j = 0;
  int cnt = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }

  return cnt;
}

int
mergeSort(int A[], int left, int right)
{
  int cnt = 0;
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    cnt += mergeSort(A, left, mid);
    cnt += mergeSort(A, mid, right);
    cnt += merge(A, left, mid, right);
  }
  return cnt;
}

int
main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto A = make_unique<int[]>(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int cnt = mergeSort(A.get(), 0, n);

  if (n > 0) {
    cout << A[0];
  }
  for (int i = 1; i < n; i++) {
    cout << " " << A[i];
  }
  cout << "\n";
  cout << cnt << "\n";

  return 0;
}

