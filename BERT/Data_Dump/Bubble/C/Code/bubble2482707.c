#include<stdio.h>
#define N 100

int main(){
  int A[N], n, i, j, a;
  int count=0;

  scanf("%d", &n);

  for(i =0; i < n; i++)
    scanf("%d", &A[i]);

  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i == n-1) break;
    printf(" ");
  }

  printf("\n%d\n", count);
  return 0;
}
