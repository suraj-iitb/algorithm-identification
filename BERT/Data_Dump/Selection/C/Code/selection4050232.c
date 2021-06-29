#include<stdio.h>
int main(){
  int A[101], n, i, j, tmp, cnt = 0, m;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  
  

  for ( i = 1; i <= n; i++ ){
    m = i;
    for ( j = i; j <= n; j++ ){
      if ( A[j] < A[m]) m = j;
    }
    tmp = A[i]; A[i] = A[m]; 
    A[m] = tmp;
    if ( i != m ) cnt++;
  }
  
  

  for ( i = 1; i <= n; i++ ){
    if (i>1) printf(" ");
    printf("%d", A[i]);
  }
  
  
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

