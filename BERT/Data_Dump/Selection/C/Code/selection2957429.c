#include<stdio.h>
int main()
{
  int N,i,j,k,minj,count=0;
  int A[100];

  scanf("%d",&N);
  for(i=0; i<N; i++)
    scanf("%d",&A[i]);

  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j]<A[minj])
	minj = j;
    }
    if(i != minj){
      count++;
      k = A[i];
      A[i] = A[minj];
      A[minj] = k;
    }
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  
  printf("%d",A[N-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

