#include<cstdio>

#define  MAX 5000000
#define SENTINEL 2000000000

int S[MAX];
int L[MAX/2+2], R[MAX/2+2];
int ans;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++) L[i] = A[left+i];
  for (int i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = R[n2] = SENTINEL;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    ans++; // 比較回数を足す
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  ans = 0;

  int n;
  scanf("%d", &n);

  for ( int i = 0; i < n; i++) scanf("%d", &S[i]);
  mergeSort(S, 0, n);

  for ( int i = 0; i < n; i++) {
    if ( i ) printf(" ");
    printf("%d", S[i]);
  }
  printf("\n");
  printf("%d\n", ans);
  return 0;
}

