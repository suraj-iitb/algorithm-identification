#include<stdio.h>
#define N 100
int main(){
  int i,j,n,x;
  int count=0,a;
  int A[N];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a);
    A[i] = a;
  }
  for( j = 0; j < n; j++){
    for( i = n-1; i > 0; i--){
      x = A[i];
      if(A[i] < A[i-1]){
	A[i] = A[i-1];
	A[i-1] = x;
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    if(i > 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);

  return 0;
}



