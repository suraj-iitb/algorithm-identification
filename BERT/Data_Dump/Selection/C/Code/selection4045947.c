#include <stdio.h>

int main(){
  int N;
  int A[100];
  int num = 0,count = 0;
  int i,j,minj = 0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])minj = j;
    }
    if(minj!=i){
      num = A[i];
      A[i] = A[minj];
      A[minj] = num;
      count++;
    }
  }
  
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  
  printf("%d\n",count);
  
  return 0;
}

