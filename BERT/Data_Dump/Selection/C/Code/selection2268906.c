#include <stdio.h>

static const int N1 =1000;
void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main()
{
  int N, i, j, swap, minj, count = 0;
  int A[N1];
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);

  for(i = 0; i < N-1; i++){

    minj = i;
    for(j =i; j <= N-1; j++){
      if( A[j] < A[minj] ){
	minj = j;
      }
    }
	if(minj != i){
	swap = A[i];
	A[i] = A[minj];
	A[minj] = swap;
	minj = i;
	count++;
	
      }
     
    }
  trace(A, N);
  printf("%d\n", count);  
  
  return 0;
}

  
