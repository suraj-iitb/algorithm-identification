#include <stdio.h>

int main()
{

  int i, j, N, minj, b, count;

  count = 0;
  
  scanf("%d",&N);

  int A[N];
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(i!=minj) count++;
    b = A[i];
    A[i] = A[minj];
    A[minj] = b;
  }

  for(i=0;i<N;i++){
    if(i==N-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }

  printf("%d\n",count);

  return 0;

}

