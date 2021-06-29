#include <stdio.h>

int main()
{
  int i,j,minj,A[100],temp,cnt=0,N;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj)cnt++;
  } 
 
  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[N-1],cnt);

  return 0;
}
