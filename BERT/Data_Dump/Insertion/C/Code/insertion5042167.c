#include<stdio.h>

#define N 100

int main(){
  int i, j, key, n, A[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i = 1; i <= n-1; i++){
    for(key = 0; key < n-1; key++){
      printf("%d ", A[key]);
    }
    printf("%d", A[key]);
    printf("\n");
    
    key = A[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
    
  for(key = 0; key < n-1; key++){
    printf("%d ", A[key]);
  }
  printf("%d", A[key]);
  printf("\n");
  
  return 0;
}

