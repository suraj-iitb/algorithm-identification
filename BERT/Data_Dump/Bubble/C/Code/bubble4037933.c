#include<stdio.h>

int main(){
  int N,i,flag=1,j,A[100],c=0;
  scanf("%d",&N);
  for(j=0;j<N;j++)scanf("%d",&A[j]);
  while(flag){
    flag=0;//交換がおきなかったなら、ソート完了であるという判定
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	i=A[j];
	A[j]=A[j-1];
	A[j-1]=i;
	c++;
	flag=1;
      }
    }
  }
  for(j=0;j<N;j++)if(j!=N-1)printf("%d ",A[j]);else printf("%d\n",A[j]);
  printf("%d\n",c);
  return 0;
}

