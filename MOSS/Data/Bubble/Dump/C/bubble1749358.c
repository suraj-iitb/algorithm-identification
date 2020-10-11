#include <stdio.h>
int main(){
  int i,j,N,flag,count=0;
  int tmp;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  flag=1;
  while(flag==1){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	count++;
      }
    }
  }


  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n%d\n",count);
  return 0;
}
