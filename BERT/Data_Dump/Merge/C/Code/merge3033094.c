#include <stdio.h>
#include <limits.h>
int cnt = 0;

#define INFTY 1000000000

void merge(int S[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (i = 0; i < n1; i++){
    L[i] = S[left + i];
  }
  for (i = 0; i < n2; i++){
    R[i] = S[mid + i];
  }
  L[n1] = INT_MAX; // intの最大値
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  for (k = left; k < right; k++){
    cnt++;
    if (L[i] <= R[j]){
      S[k] = L[i++];
    } else {
      S[k] = R[j++];
    }
  }
  return;
}

void mergeSort(int S[], int left, int right){
  if (left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
  return;
}

int main(){
  int i, n, S[500000];
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  mergeSort(S, 0, n);
  printf("%d", S[0]);
  for (i = 1; i < n; i++) {
    printf(" %d", S[i]);
  }
  printf("\n");
  printf("%d\n", cnt);
  return 0;
}

