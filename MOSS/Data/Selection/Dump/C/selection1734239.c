#include <stdio.h>
int main()
{
  int N,A[100],i,j,minj,flag,a,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }


  for(i=0;i<N-1;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(minj!=i){
    a = A[i];
    A[i] = A[minj];
    A[minj]=a;
    count++;
    }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);

  printf("%d\n",count);

  return 0;
}
