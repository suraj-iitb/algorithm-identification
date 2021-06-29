#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void Sort(int A[],int n){
  int i,j,k;
  for(i=1;i<n;i++){
    k =A[i];
    j = i-1;
    while(j >= 0 && A[j] > k){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = k;
    trace(A,n);
  }
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  trace(A, n);
  Sort(A,n);

  return 0;
}
