
#include <stdio.h>


int main(){

  long i;
  long n, q;
  long S[100001], T[50001];
  long mc; //matchCounter
  long ps, pe; //pointStart, pointEnd
  long cp; //checkPoint

  // input
  scanf( "%ld", &n );

  for( i=0; i<n; i++ )
    scanf( "%ld", &S[i] );

  scanf( "%ld", &q );
  
  for( i=0; i<q; i++ )
    scanf( "%ld", &T[i] );

  // binary search
  mc=0;
  for( i=0; i<q; i++ ){

    // case 1
    if( T[i] > S[n-1] ) continue;

    // case 2
    ps = 0; pe = n;
    while( ps <= pe ){
      cp = ps + (pe - ps) / 2;
      if( T[i] == S[cp]){ 
        mc++;
        break;
      }
      if( T[i] < S[cp]) pe = cp-1;
      if( T[i] > S[cp]) ps = cp+1;
    }
  }

  // result
  printf( "%ld\n", mc );

  return 0;
}

