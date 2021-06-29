#include <stdio.h>

int main(void){
  int i,j,n,q;
  int cnt	= 0;
  long long int S[10001],T[501];

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ) scanf("%lld",&S[i]);
  scanf("%d",&q);
  for( i = 0 ; i < q ; i++ ) scanf("%lld",&T[i]);
  for( i = 0 ; i < q ; i++ ){
    for( j = 0 ; j < n ; j++ ){
      if( S[j] == T[i] ){
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
