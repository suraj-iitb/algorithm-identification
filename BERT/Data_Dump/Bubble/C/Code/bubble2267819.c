#include <stdio.h>
int main(){
  int i,flag=1,times=0,temp,N;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  while(flag){
    flag=0;
    for(i=N-1;i>=0;i--){
      if(A[i]<A[i-1]){
	temp=A[i];
	A[i]=A[i-1];
	A[i-1]=temp;

	times++;
	flag=1;
      }
    }
  }

  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  
  printf("%d\n",times);
  
    return 0;
}
