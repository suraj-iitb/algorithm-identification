#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j,key;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  
  
  trace(A, n);
  /*

    your code

   */
  for(j = 2;j <= n;j ++)
    {
      key = A[j];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
      i = j - 1;
      
	while(i >= 0 && A[i] > key)
	  {
	    A[i+1] = A[i];
	    i = i - 1;
	  }
	    A[i + 1] = key;
	    trace(A,n);
    }
  

  return 0;
}
