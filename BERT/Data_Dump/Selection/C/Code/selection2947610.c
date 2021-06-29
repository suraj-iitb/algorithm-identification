#include <stdio.h>

int main(){
  int i,j;
  int minj;
  int N;
  int a;
  int count=0;

  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj=j;
      }
    }
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
    if(i!=minj)count++;
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d\n",A[i]);
      printf("%d\n",count);
    }
    else printf("%d ",A[i]);
  }
    
  return 0;
}

