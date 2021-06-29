#include<stdio.h>
#include<stdlib.h>


int main(){
  int n,i;
  int *A;
  int *B;
  int c[10001];

  for(i=0;i<10001;i++)
    c[i]=0;

  scanf("%d",&n);
  A = malloc(sizeof(int)*n);
  B = malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    c[A[i]]++;
  }

  for(i=1;i<10001;i++)
    c[i] = c[i]+c[i-1];

  for(i=n-1;i>=0;i--){
    B[c[A[i]]-1] = A[i];
    c[A[i]]--;
  }

  for(i=0;i<n-1;i++)
    printf("%d ",B[i]);

  printf("%d\n",B[n-1]);

  return 0;
}
