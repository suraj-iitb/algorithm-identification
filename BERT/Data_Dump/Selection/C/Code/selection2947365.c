#include<stdio.h>
#define N 100

int main(){
  int A[N], n, i, j, minj, change, cont = 0;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &A[i]);

  for(i=0; i<n-1; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] != A[minj]){
    change = A[i];
    A[i] = A[minj];
    A[minj] = change;
    cont++;
    }  
  }

  for(i=0; i<n-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[n-1]);
  printf("%d\n", cont);
  
  return 0;
}

