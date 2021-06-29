#include<stdio.h>
#define N 101

void insertionSort(int *, int);

int main(){
  int i, n, A[N];
  scanf("%d", &n);
  for(i=0; i<n; i++)scanf("%d", &A[i]);

  insertionSort(A, n);

  return 0;
}

void insertionSort(int *A, int n){
  int i, j, v;

  for(i=0; i<n; i++){
    printf("%d", A[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  
  for(i=1; i<n; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(j=0; j<n; j++){
      printf("%d", A[j]);
      if(j == n-1)printf("\n");
      else printf(" ");
    }
    
  }
}

