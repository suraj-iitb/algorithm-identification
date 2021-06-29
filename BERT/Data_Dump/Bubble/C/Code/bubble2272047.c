#include <stdio.h>
#include <stdlib.h>

#define N 101

int bubblesort(int *, int);

int main() {
  int i, n, c;
  int A[N];

  scanf("%d",&n);
  if(n<0 || n>101) exit(1);

  for(i=0;i<n;i++) scanf("%d", &A[i]);

  c=bubblesort(A, n);
  for(i=0;i<n-1;i++) printf("%d ", A[i]);
  printf("%d\n", A[i]);
  printf("%d\n", c);

  return 0;
}

int bubblesort(int *A, int n){
  int i, j, temp;
  int c=0, flag=1;
  while(flag){
    flag=0;
    for(i=0;i<n-1;i++){
      for(j=n-1;j>i;j--){
	if(A[j]<A[j-1]){
	  temp=A[j];
	  A[j]=A[j-1];
	  A[j-1]=temp;
	  flag=1;
	  c++;
	}
      }
    }
  }
  return c;
  
}
