#include<stdio.h>

static const int N = 100;

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
  
    for(j = 2; j <= n+1; j++){

      trace(A, n);

      key = A[j];
      //A[j]をソート済みの列A[1..j-1]に代入する
    
      i = j-1;
      
      
      while(i>0 && A[i]>key){
	
	A[i+1] = A[i];
	i = i - 1;
	A[i+1] = key;
      }
    }  
    return 0;
}
