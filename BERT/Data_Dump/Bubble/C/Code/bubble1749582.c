#include <stdio.h>
int main(){
  int N,A[100],i,x=0,y=0,flag=1;

  scanf("%d",&N);
  if(N>=1 && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
  }
  while(flag){
    flag=0;
  for(i=N-1;i>=1;i--)
    {
      if(A[i] < A[i-1]){
	x=A[i];
      A[i]=A[i-1];
      A[i-1]=x;
      y++;
      flag=1;
      }
    }
  }

  for(i=0;i<N;i++)
{
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
    printf("\n%d\n",y);

    return 0;
  }
