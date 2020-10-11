#include <stdio.h>
#define num 100
int main(){
  int i,j,N,A[num],flag=1,st,co=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	st = A[j-1];
	A[j-1] = A[j];
	A[j] = st;
	flag = 1;
	co += 1;
      }
    }
  }

  for(i=0;i<N;i++){
    if(i != N-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",co);

  return 0;
}

