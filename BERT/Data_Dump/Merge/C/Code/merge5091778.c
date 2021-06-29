#include <stdio.h>
#include <math.h>
#define INFTY 500000

int S[INFTY], count = 0;

void merge(int left, int mid, int right){
  int i, j, n1, n2, L[INFTY], R[INFTY];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i<n1; i++){
    L[i] = S[left + i];
  }
  for(i = 0; i<n2; i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;

  i = 0;
  j = 0;
  for(int k = left; k < right; k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
      count++;
    }else{
      S[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}

int mergeSort(int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
  else return 0;
}

int main(){
  int i, n;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(0, n);

  for(i = 0; i<n-1; i++){
    printf("%d ", S[i]);
  }

  printf("%d\n%d\n", S[i], count);

  return 0;

}

