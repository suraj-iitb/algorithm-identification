#include<stdio.h>
#define MAX 100

int main()
{
  int count=0,temp,flag,i,j,A[MAX],N,result;

  result=scanf("%d",&N);

  if(result>=1 && result<=100){
    
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    flag=1;

    while(flag){

      flag=0;

      for(j=N-1;j>0;j--){

	if(A[j]<A[j-1]){
	  
	  temp=A[j-1];
	  A[j-1]=A[j];
	  A[j]=temp;
	  flag=1;
	  count++;
	}
      }
    }
    for(i=0;i<N-1;i++) printf("%d ",A[i]);
    printf("%d\n",A[i]);
    printf("%d\n",count);
  }
  return 0;
}
