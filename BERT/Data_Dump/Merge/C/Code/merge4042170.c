#include<stdio.h>
#define N_MAX 500000
#define S_MAX 1000000000
#define INFTY S_MAX+1

int L[N_MAX/2+2];
int R[N_MAX/2+2];

long count; // 比較回数

void merge(int *A, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;

  // L[0...n1], R[0...n2] を生成
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  
  L[n1] = INFTY; // 番兵を入れる
  R[n2] = INFTY; // 番兵を入れる
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    count++;  // 比較回数をカウント
    if (L[i] <= R[j]) { // 小さいほうを A にコピー
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}
                
void mergeSort(int *A, int left, int right)
{
  int mid;
  
  if (left+1 < right) {
    mid = (left + right)/2;

    mergeSort(A, left, mid);
    mergeSort(A, mid, right);

    merge(A, left, mid, right);
  }
}

int main(void)
{
  int n;
  int A[N_MAX];
  int i;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  mergeSort(A, 0, n);

  for(i=0; i<n-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[n-1]);

  printf("%ld\n", count);
  
  return 0;
}

