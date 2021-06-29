#include<stdio.h>
int main()
{
  int a,b,i,min,v,N,count=0;
  int A[100];

  scanf("%d",&N);
  for(a=0;a<=N-1;a++)scanf("%d",&A[a]);
  for(a=0 ;a<=N-1 ;a++){
    v = A[a];
    min = 100;
    for(i=a+1;i<=N-1;i++){
      if(min > A[i]){
	min = A[i];
	b = i;
      }
    }
    if(min < v){
      A[a] = min;
      A[b] = v;
      count++;
    }
  }
  for(a=0 ;a<=N-2 ;a++)printf("%d ",A[a]);
  printf("%d\n",A[a]);
  printf("%d\n",count);
  return 0;
} 

