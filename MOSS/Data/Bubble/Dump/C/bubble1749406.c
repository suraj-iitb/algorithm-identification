#include <stdio.h>

int main()
{
  int N, i, flag=1, work, count=0, A[100];

  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }

  while(flag==1){
    flag=0;
    for(i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
	work=A[i];
	A[i]=A[i-1];
	A[i-1]=work;
	flag=1;
	count++;
      }
    }
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d",A[i]);
      break;
    }
    printf("%d ", A[i]);
  }

  printf("\n%d\n", count);
  
  return 0;
}
