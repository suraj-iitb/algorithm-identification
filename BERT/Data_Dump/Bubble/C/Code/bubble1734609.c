#include <stdio.h>

int main()
{
  int A[100],N,flag=1,j,i,temp,count;

    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    i=0;
    while(flag){
      flag=0;
      for(j=N-1;j>=i+1;j--){
	if(A[j]<A[j-1]){
	  temp = A[j];
	  A[j] = A[j-1];
	  A[j-1] = temp;
	  flag=1;
	  count++;
	}
      }
      if(flag==1){
	i+=1;
      }
    }
    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[N-1]);
    printf("\n");
    printf("%d\n",count);

    return 0;
}
