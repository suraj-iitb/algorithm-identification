#include<stdio.h>
#define N 100

int bubbleSort(int *, int);

int main(){
  int i, n, A[N], count;

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  count = bubbleSort(A, n);

  for(i=0; i<n; i++){
    printf("%d", A[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n", count);

  return 0;
}

int bubbleSort(int *A, int n){
  int i, a, count=0, flag=1;

  while(flag){
    flag = 0;
    for(i=n-1; i>0; i--){
      if(A[i] < A[i-1]){
	a = A[i];
	A[i] = A[i-1];
	A[i-1] = a;
	flag = 1;
	count++;
      }
    }
  }

  return count;
}

