#include <stdio.h>


int main(){

  int n, q;
  long S[10001], T[501];

  int i,j;
  int c; //counter

  scanf( "%d\n", &n );

  for( i=0; i<n; i++ )
    scanf( "%ld", &S[i] );

  scanf( "%d\n", &q );
  
  for( i=0; i<q; i++ )
    scanf( "%ld", &T[i] );


  c=0;
  for( i=0; i<q; i++ ){
    for( j=0; j<n; j++ ){
      if( S[j] == T[i] ){
        c++;
        break;
      }
    }
  }


  printf( "%d\n", c );

  return 0;
}

