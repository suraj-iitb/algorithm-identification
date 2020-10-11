
#include <stdio.h>
#define X 100
int main()
{
  int N,i,A[X],flag=1,j,temp,count=0,minj;

  scanf("%d",&N);

  if(N>=1 && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    i=0;
    for(i=0;i<N;i++){
      minj=i;
      for(j=i;j<N;j++){ 
	if(A[j]<A[minj]){
	  minj=j;
	}
      }
      if(A[i]!=A[minj]){
	temp=A[i];
	A[i]=A[minj];
	A[minj]=temp;
	count++;
      }
    }
    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[N-1]);
    printf("\n%d\n",count);
  }
  return 0;
}
