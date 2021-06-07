#include<stdio.h>
int binarysearch(int);

int S[100000], n;

int main(){
  int q, i, C=0;
  int T[50000];

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for( i = 0 ; i < q ; i++ ){
    scanf("%d", &T[i]);
    if( binarysearch(T[i]) ) C++;
  }
  printf("%d\n", C);
  return 0;
}

int binarysearch(int t){
  int l=0, r=n, mid;
  while( l < r ){
    mid = ( l + r ) / 2;
    if( t == S[mid] ) return 1;
    if( t > S[mid] ) l = mid + 1;
    else if( t < S[mid] ) r = mid;
  }
  return 0;
}

