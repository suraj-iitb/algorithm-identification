#include <stdio.h>
#define num 100

int main(){
  int N,i,count=0,flag,stac,A[num];

  scanf("%d",&N);

  for(i=0;i<N;i++)scanf("%d",&A[i]);

  flag=1;
  while(flag){
    flag=0;
    for(i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
	stac=A[i];
	A[i]=A[i-1];
	A[i-1]=stac;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[N-1],count);

  return 0;
}
