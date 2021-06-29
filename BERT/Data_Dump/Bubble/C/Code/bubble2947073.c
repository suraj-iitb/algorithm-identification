#include<stdio.h>
#define N 100

int main(){
  int n, A[N], i, j, change, flag, cont=0;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &A[i]);

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      flag = 0;
      if(A[j] < A[j-1]){
	change = A[j];
	A[j] = A[j-1];
	A[j-1] = change;
	flag = 1;
      }
       if(flag == 1) cont++;
    }
  }

  for(i=0; i<n-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[n-1]);
  printf("%d\n", cont);
  
  return 0;
}

