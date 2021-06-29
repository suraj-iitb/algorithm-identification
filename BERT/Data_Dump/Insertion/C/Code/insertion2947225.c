#include <stdio.h>

int main()
{
 
  int i, j, tmp, l;
  int N;
  int A[1000];
 
  scanf("%d", &N);
  
  for(i=0; i<N; i++){
 
  scanf("%d",&A[i]);
  
  }

  for(i=1; i<N; i++){
      for(j=0; j<N-1; j++){ 
      printf("%d ",A[j]);
    }
    printf("%d\n",A[N-1]);
    tmp=A[i];/*i*/
    if(A[i-1]>tmp){/*i-1*/
      l=i;/*i*/
      do{
	A[l]=A[l-1];
	l--;
      }
      while(l>0 && tmp<A[l-1]);
      A[l]=tmp;
    }
  }

  for(j=0; j<N-1; j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[N-1]);
  return 0;
}

