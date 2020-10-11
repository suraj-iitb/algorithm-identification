#include <stdio.h>
#define X 100
int main()
{
  int N,i,A[X],flag=1,j,temp,count=0;

  scanf("%d",&N);

  if(N>=1 && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    i=0;
    while(flag==1){
      flag=0;
      for(j=N-1;j>=i+1;j--){
	if(A[j]<A[j-1]){
	  temp=A[j];
	  A[j]=A[j-1];
	  A[j-1]=temp;
	  flag=1;
	  count+=1;
	}
      }
      if(flag==1){
	i=+1;
      }    }
    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[N-1]);
    printf("\n%d\n",count);
  }
  return 0;
}

 
