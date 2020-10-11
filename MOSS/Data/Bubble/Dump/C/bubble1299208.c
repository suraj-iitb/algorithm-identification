#include <stdio.h>
#define N 100

int main(){
  int i, j, c=0, n, A[N], key=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

    for(i = 0; i < n-1; i++){
      for(j = 0; j < n-1; j++){
	if(A[j] > A[j+1]) {
	  key = A[j];
	  A[j] = A[j+1];
	  A[j+1] = key;
	  c++;
	}
      }
    }
    
  
    
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",c);
    
  return 0;
}
