#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000;
int L[500010];
int R[500010];
int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  // L, R配列を生成
  for (int i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  // 番兵を設定
  int sentinel = INF;
  L[n1] = R[n2] = sentinel;
  // マージ
  int i = 0, j = 0;
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
}

// マージソート
void mergeSort (int A[], int n, int left, int right) {
  if (left+1 < right)
  {
    int mid = (left + right) * 0.5;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, left, mid, right);
  }
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  /* マージソート */
  mergeSort(A, n, 0, n);

  /* 出力 */
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}

