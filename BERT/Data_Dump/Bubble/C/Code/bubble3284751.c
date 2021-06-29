#include<stdio.h>
int main()
{
  int a,j,v,N,count=0;
  int A[100];

  scanf("%d",&N);
  for(a=0;a<=N-1;a++)scanf("%d ",&A[a]);
  for(a=1 ;a<=N-1 ;a++){
    v = A[a];
    j = a-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
      count++;
    }
  }
  for(a=0 ;a<=N-2 ;a++)printf("%d ",A[a]);
  printf("%d\n",A[a]);
  printf("%d\n",count);
  return 0;
}

