#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define iin(x) scanf("%d", &x)
#define lin(x) scanf("%lld", &x)
#define fin(x) scanf("%lf", &x)

#define iout(x) printf("%d", x)
#define lout(x) printf("%d", x)
#define fout(x) printf("%.10f", x)
#define _ putchar(' ')
#define endl puts("")

#define reps(i, x, n) for(i = (x); i < (n); i++)
#define rep(i, n) reps(i, 0, n)

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[500001], R[500001];
  int i, j, k;
  rep(i, n1) L[i] = A[left+i];
  rep(i, n2) R[i] = A[mid+i];
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  i = 0, j = 0;
  reps(k, left, right) {
    cnt++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right) {
  if(left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n; iin(n);
  int A[500001];
  int i;
  rep(i, n) iin(A[i]);
  mergeSort(A, 0, n);
  rep(i, n) {
    if(i) _;
    iout(A[i]);
  }
  endl;
  iout(cnt),endl;
  return 0;
}
