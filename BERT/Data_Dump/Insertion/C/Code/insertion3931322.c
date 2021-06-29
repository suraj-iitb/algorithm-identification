#include<stdio.h>
int main()
{
  int A[1000],N,j,i,v;
  scanf("%d",&N);
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<=N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;

    for(j=1;j<N;j++)printf("%d ",A[j]);
    printf("%d\n",A[N]);
  }
  return 0;
}


