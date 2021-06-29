#include <stdio.h>
#include <stdlib.h>
#define K 10000

int main(){
  int n,*A,*b,c[K],i;
  scanf("%d",&n);
  A=(int *)malloc(n*sizeof(int));
  b=(int *)malloc(n*sizeof(int));
  
  for(i=0;i<=K;i++)
    c[i]=0;
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    c[A[i]]++;
  }

  for(i=1;i<=K;i++)
    c[i]+=c[i-1];

  for(i=n-1;i>=0;i--)
    b[--c[A[i]]]=A[i];

  for(i=0;i<n-1;i++)
    printf("%d ",b[i]);
  printf("%d\n",b[n-1]);
  
  return 0;
}

