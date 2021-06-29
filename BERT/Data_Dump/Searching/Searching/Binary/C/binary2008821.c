#include<stdio.h>
int main(){

  int i,j,n,q,S[100001],T[50001];

  scanf("%d", &n );
  for ( i = 0; i < n; i++ ){
    scanf("%d", &S[i] );
  }

  scanf("%d", &q );
  for ( i = 0; i < q; i++ ){
    scanf("%d", &T[i] );
  }

  int left,mid,right,key,cnt;
  cnt = 0;

  for ( i = 0; i < q; i++ ){

    left = 0;
    right = n - 1;
    key = T[i];

    while( left < right ){

      if ( key == S[right] ){
	cnt += 1;
	break;
      }

      mid = ( left + right ) / 2;

      if ( S[mid] > key ){
	right = mid;
      } else if ( S[mid] < key ){
	left = mid + 1;
      } else {
	cnt +=1;
	break;
      }

    }

  }

  printf("%d\n", cnt );
  
  return 0;
  
}
