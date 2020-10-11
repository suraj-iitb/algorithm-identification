#include<stdio.h>
#include<stdlib.h>

#define N 101

int selectionSort(int *, int);

int main() {
  int i, n, c;
  int A[N];
  
  scanf("%d", &n);
  if(n<0 || n>100) exit(1);

  for(i=0;i<n;i++) scanf("%d", &A[i]);

  c = selectionSort(A, n);

  for(i=0;i<n-1;i++) printf("%d ", A[i]);
  printf("%d\n%d\n", A[i], c);

  return 0;
}

int selectionSort(int *A, int n){
  int i, j, m, temp;
  int c=0;

  for(i=0;i<n;i++){
    m=i;
    for(j=i+1;j<n;j++){
      if(A[j]<A[m]) m=j;
    }

    if(i!=m){
      temp=A[i];
      A[i]=A[m];
      A[m]=temp;
      c++;
    }
  }
  return c;
}
