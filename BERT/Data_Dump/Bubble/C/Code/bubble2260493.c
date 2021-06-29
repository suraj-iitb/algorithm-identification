#include<stdio.h>

static const int N = 100;

int main(){
  int n, i, j;
  int A[N];
  int count=0;
  int tmp;


  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
  }  

  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	count++;
      }
    }
  }
  
  
  for ( i = 0; i < n; i++ ){
    if ( i >= 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  
  printf("%d\n",count);


  return 0;
}
