#include <stdio.h>
#define N 2000002
#define MAX 10000


int A[N],B[N];
int main(){
  
  int C[MAX+1];
  int n, i, j;
  

 
  /*配列cの初期化*/
  for ( i = 0; i <= MAX; i++ ) C[i] = 0;


  /*データの読取*/
 scanf("%d", &n);

  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i + 1]);
    C[A[i + 1]]++;
  }


  /* C[i] に i 以下の数の出現数を記録する*/
  for ( i = 1; i <= MAX; i++ ) C[i] = C[i] + C[i - 1];




  for ( j = 1; j <= n; j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }



  /*表示*/
  for ( i = 1; i <n; i++ ){ 
    printf("%d ", B[i]);
  }
  printf("%d\n",B[i]);

  return 0;
}
