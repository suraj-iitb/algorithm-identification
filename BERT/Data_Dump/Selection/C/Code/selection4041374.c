#include<stdio.h>

void selectionSort(int A[],int n);

int main(){
  int A[100], n, i, j, t, cnt = 0, minj;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for ( i = 0; i < n; i++ ){
    minj = i;
    for ( j = i; j < n; j++ ){
      if ( A[j] < A[minj] ) minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    if ( i != minj ) cnt++;
  }

  selectionSort(A,n);
  
  printf("%d\n", cnt);

  return 0;
}

void selectionSort(int A[],int n){
  int i;
  
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

