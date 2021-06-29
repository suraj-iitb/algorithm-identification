#include<stdio.h>

static const int N = 100;

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  int key;
  for(i=0;i<=n-1;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }
    
    int m;
    for ( m = 0; m <= n-1; m++ ){
      if ( m > 0 ) printf(" ");
      printf("%d", A[m]);
    }
    printf("\n");
  }
  
  return 0;
}
