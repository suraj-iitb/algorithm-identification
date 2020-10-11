#include<stdio.h>

int main()
{   
    int A[100];
    int t,N,count=0;
    int i,j,flag=1;
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    while(flag){
      flag=0;
      for(j=N-1;j>=1;j--)
        {
	  if(A[j]<A[j-1])
            {
	      t=A[j];
	      A[j]=A[j-1];
	      A[j-1]=t;
	      flag=1;
	      count++;
            }
        }      
    }
    for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
    }
    printf("%d",A[N-1]);
    printf("\n%d\n",count);
    return 0;
}

