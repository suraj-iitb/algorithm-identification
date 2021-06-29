#include<stdio.h>
#define N 100
int main(){
  int A[N],n,i,j,count=0;
  int minj=101,x,y,w;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);

  for(i = 0; i < n-1; i++){
    minj = i;
    x = A[i];
    for( j = i; j < n; j++){
      if(A[j] < A[minj])
	minj = j;
    }
    A[i] = A[minj];
    A[minj] = x;
    if( i != minj)
      count++;
  }
  

 
  for(i = 0; i < n; i++){
    if( i > 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);

  return 0;
}



