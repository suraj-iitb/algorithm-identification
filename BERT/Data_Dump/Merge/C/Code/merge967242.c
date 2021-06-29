#include <stdio.h>
#define SENTINEL 1000000000
#define N 500000
int array[N], count = 0;

void Marge(int left, int mid, int right){
  int n1, n2, i, j;
  n1 = mid - left;
  n2 = right - mid;

  int L[n1+1], R[n2+1];
  for(i = 0; i < n1; i++){
    L[i] = array[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = array[mid + i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  int k;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      count++;
      array[k] = L[i];
      i++;
    }else{
      array[k] = R[j];
      j++;
      count++;
    }
  }
}

void MargeSort(int left, int right){
  int mid;
  if((left + 1) < right){
    mid = (left + right) / 2;
    MargeSort(left, mid);
    MargeSort(mid, right);
    Marge(left, mid, right);
  }
}

main(){
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  MargeSort(0, n);
  
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d", array[i]);
  }
    printf("\n");
    printf("%d\n", count);
  return 0;
}
