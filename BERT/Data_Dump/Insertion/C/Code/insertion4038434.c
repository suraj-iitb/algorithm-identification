#include<stdio.h>
int main(){
  int N,A[1000],v;
  int i,j;
  scanf("%d",&N);
  for(i=0;i<=N-1;i++)scanf("%d",&A[i]);
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(j=0;j<N-1;j++)printf("%d ",A[j]);
    printf("%d\n",A[N-1]);
  }
  return 0;
}
