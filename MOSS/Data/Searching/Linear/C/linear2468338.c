#include<stdio.h>
int main(){
 
  int i,j,n,q,S[10001],T[501];
 
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%d", &S[i] );
  }
 
  scanf("%d", &q );
  for ( i = 0; i < q; i++ ){
    scanf("%d", &T[i] );
  }
 
  int key,cnt;
  cnt = 0;
 
  for ( i = 0; i < q; i++ ){
    key = T[i];
    for ( j = 0; j < n; j++ ){
      if ( S[j] == key ){
    cnt += 1;
    break;
      } 
    }
  }
 
  printf("%d\n", cnt );
 
  return 0;
 
}
