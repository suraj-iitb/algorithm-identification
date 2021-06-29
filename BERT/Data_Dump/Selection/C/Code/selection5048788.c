#include<stdio.h>
#define MAX 100

int main()
{
  int N,i,j,mini,temp,count=0,result,A[MAX];
  
  result=scanf("%d",&N);

  if(result>=1 && result<=100){

    for(i=0;i<N;i++) scanf("%d",&A[i]);

    for(i=0;i<N-1;i++){

      mini=i;

      for(j=i;j<=N-1;j++){

	if(A[j]<A[mini]){

	  mini=j;
          
	}
      }
      
	temp=A[mini];
	A[mini]=A[i];
	A[i]=temp;
	if(mini!=i)count++;
      
    }

    for(i=0;i<N-1;i++) printf("%d ",A[i]);
    
    printf("%d\n",A[i]);
    printf("%d\n",count);
  }
    return 0;
}
