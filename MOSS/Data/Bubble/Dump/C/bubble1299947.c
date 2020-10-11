#include <stdio.h>

int main()
{
  int A[100];
  int i=0, j=0, n=0, N=0;
  int a;
  int flag=1;
  
  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  while(flag){
    flag = 0;
    for(j=N-1; 0<j; j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	flag = 1;
	n++;
      }
    }
  }
  for(i=0; i<N; i++){
    printf("%d", A[i]);
    if(i==N-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n", n);
  return 0;
}
