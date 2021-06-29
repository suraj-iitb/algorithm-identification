#include<stdio.h>

static const int N = 100;

int main(){
  int n, i, j;
  int A[N];
  int count=0;
  int tmp;
  int minj;


  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
  }  

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      if(i != minj){
	count++;
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
