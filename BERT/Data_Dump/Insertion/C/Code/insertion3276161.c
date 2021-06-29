#include<stdio.h>
int main(){
  int i,j,k,N,v;
  int A[1000];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1) printf(" ");
    }
  printf("%d",A[N-1]);
  printf("\n");
  for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
  while(j>=0 && A[j]>v)
    {
      A[j+1]=A[j];
	j--;
    }
  A[j+1]=v;
  for(k=0;k<N-1;k++)
    {
      printf("%d",A[k]);
      if(k!=N-1) printf(" ");
    }
  printf("%d",A[N-1]);
  printf("\n");
    }
  return 0;
}

