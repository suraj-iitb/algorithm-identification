#include <stdio.h>

int main()
{
 
  int i, j, tmp, c;
  int N;
  int A[100];
 
  scanf("%d", &N);
  
  for(i=0; i<N; i++){
  scanf("%d",&A[i]);
  }

  for(i=0; i<N-1; i++){
    for(j=N-1; j>i; j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	c++;
      }
    }
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",c);
  return 0;
}

