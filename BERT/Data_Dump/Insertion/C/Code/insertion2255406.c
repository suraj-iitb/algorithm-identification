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

int main() 
{
  int i,j,v,n;
  int A[N+1];

  scanf("%d", &n);
  
  for ( i = 1; i <= n; i++ ){
    if(scanf("%d", &A[i])==EOF)break;
    
  }  
  trace(A,n);
  for(i=2;i<=n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
	A[j+1]=A[j];
	j=j-1;	
	A[j+1]=v;
	//	trace(A,n);
      }
    trace(A,n);

  }//trace(A,n);
  return 0;
}