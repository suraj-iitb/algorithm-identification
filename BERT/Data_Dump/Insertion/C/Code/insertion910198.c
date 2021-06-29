#include <stdio.h>

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

  int n; 
  int i,j;
  int A[N+1];
  
  scanf("%d",&n);
  
  for( i=1 ; i <= n ; i++ ) scanf("%d",&A[i]);

 
  for( i=1 ; i <= n ; i++ ){
    
    if(A[i]<A[i-1]){
      //switch
      int a;
      a = A[i];
      A[i]=A[i-1];
      A[i-1]=a;
    }
    for( j=i-1 ; j>0 ; j-- ){
      if(A[j]<A[j-1]){
	//switch
	int b;
	b = A[j];
	A[j]=A[j-1];
	A[j-1]=b;
      }
    }
    trace(A, n);      
  }
  
  return 0;
  
}
