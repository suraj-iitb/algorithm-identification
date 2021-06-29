#include<stdio.h>
int main( )
{
  int i, j,mini,temp,count=0;
  int A[100],N;
  scanf("%d",&N);
  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i < N-1; i++){
    mini = i;
    for(j = i+1; j < N; j++){
      if(A[j]<A[mini]){
	mini = j;
      }
    }
    temp = A[i];
    A[i] = A[mini];
    A[mini] = temp;
    if(i != mini){
    count++;
    }
  }
  for(i = 0; i < N ; i++){
    if(i == N-1){
      printf("%d",A[i]);
    }
    else printf("%d ",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
