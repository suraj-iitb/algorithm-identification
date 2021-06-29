#include <bits/stdc++.h>
using namespace std;

struct Card
{
  char suit;
  int value;
};

#define INF 2000000000;
struct Card L[500010], R[500010];

// merge
void merge(struct Card A[], int n, int left, int mid, int right);
// mergeSort
void mergeSort(struct Card A[], int n, int left, int right);
// partition
int partition(struct Card A[], int n, int p, int r);
// quickSort
void quickSort(struct Card A[], int n, int p, int r);

int main(int argc, char const *argv[])
{
  int n, tmp;
  cin >> n;
  struct Card A[n], B[n];
  char S[10];
  int stable = 1;
  for (int i = 0; i < n; i++) {
    cin >> S >> tmp;
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = tmp;
  }

  // ソート
  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  // ソート結果の比較
  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      stable = 0;
    }
  }

  // 出力
  if (stable == 1)
  {
    cout << "Stable" << endl;
  }
  else
  {
    cout << "Not stable" << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << B[i].suit << " " << B[i].value << endl;
  }

  return 0;
}

// merge
void merge(struct Card A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  // L, R配列を生成
  for (int i = 0; i < n1; i++)
  {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = A[mid + i];
  }
  // 番兵を設定
  int sentinel = INF;
  L[n1].value = R[n2].value = sentinel;
  // マージ
  int i = 0, j = 0;
  for (int k = left; k < right; k++)
  {
    if (L[i].value <= R[j].value)
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
}

// mergeSort
void mergeSort(struct Card A[], int n, int left, int right){
  if (left + 1 < right)
  {
    int mid = (left + right) * 0.5;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

// partition
int partition(struct Card A[], int n, int p, int r)
{
  struct Card t, x;
  x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
  {
    if (A[j].value <= x.value)
    {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

// quickSort
void quickSort(struct Card A[], int n, int p, int r) {
  if (p < r)
  {
    int q = partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}

