#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, k=0, c=0, n, q;
  int S[10000];
  int T[500];

  scanf("%d",&n);
  if( n>10000 ) exit(1);

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&S[i]);
    if( S[i]<0 || 1000000000<S[i] ) exit(2);
  }

  scanf("%d",&q);
  if( q>500 ) exit(3);

  for( i=0 ; i<q ; i++ ){
    scanf("%d",&T[i]);
    if( T[i]<0 || 1000000000<T[i] ) exit(4);
  }
       
  for( i=0 ; i<n ; i++ ){
    for( j=0 ; j<q ; j++ ){
      if(S[i] == T[j]){
	c++;
	T[j] = T[q-1];
	q--;
	break;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}
