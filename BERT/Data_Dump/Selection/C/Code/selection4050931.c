#include<stdio.h>
int main(){
  int i,j,A[100],minj;
  int N,a,count=0,num=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])/*今比べてるやつが最小値より小さいか判別する*/
	minj=j;
    }
    if(A[i]==A[minj])num++;
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
    count++;
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count-num);
  return 0;
}
