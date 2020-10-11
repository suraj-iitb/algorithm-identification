#include<stdio.h>

void swap(int *,int *);

main(){

  int N;
  int i,j,swapc=0;
  int A[100];
  
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	swapc++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
    else if(i==N-1)printf("\n");
  }
  printf("%d\n",swapc);
  return 0;
}


void swap(int *x,int *y)
{
  int temp;

  temp=*x;
  *x=*y;
  *y=temp;
}
