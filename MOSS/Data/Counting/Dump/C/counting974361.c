#include <stdio.h>
#define N 20000001
 
int A[N];
int B[N];
int C[N];
int  n;

int main(){
 
  int i;
  int m = 0;
  scanf("%d", &n);
 
  for( i = 1; i <= n; i++ ){
    scanf("%d", &A[i]);
    if(m < A[i]){
      m = A[i];
    }
  }
 
  CountingSort( m );
   
  for( i = 1; i <= n; i++ ){
    if(i > 1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

return 0;
} 

void CountingSort( int k ){
  int i;
  int j;
  
for( i = 0; i <= k; i++ ){
    C[i] = 0;
  }
  for( j = 1; j <= n; j++ ){
     C[A[j]]++;
  }
  for( i = 1; i <= k; i++ ){
    C[i] = C[i] + C[i-1];
  }
  for( j = n; j > 0; j-- ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
 
