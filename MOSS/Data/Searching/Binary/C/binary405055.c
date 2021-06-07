#include <stdio.h>

int main(void){
  int i,n,q,mid,left,right;
  int cnt = 0;
  long long int S[100001],T[50001];

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ) scanf("%lld",&S[i]);
  scanf("%d",&q);
  for( i = 0 ; i < q ; i++ ) scanf("%lld",&T[i]);

  for( i = 0 ; i < q ; i++ ){
    right = n;
    left = 0;
    while( left < right ){
      mid = (left + right)/2;
      if( T[i] == S[mid] ){
        cnt++;
        break;
      }
      else if( T[i] < S[mid] ){
        right = mid;
      }
      else left = mid + 1;
    }
  }

  printf("%d\n",cnt);
  return 0;
}
