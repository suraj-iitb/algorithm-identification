#include<stdio.h>

int Binary(int);

int S[100000],ns;

int main(){
  int  nt, i, C=0;
  int T[100000];

  scanf("%d", &ns);

  for( i = 0 ; i < ns ; i++ ){
    scanf("%d", &S[i]);
  }

  scanf("%d", &nt);

  for( i = 0 ; i < nt ; i++ ){
    scanf("%d", &T[i]);
    if(Binary(T[i])){
       C++;
     }
  }

  printf("%d\n", C);
  return 0;
}

int Binary(int t){
  int l=0, r=ns, mid;
  while( l < r ){
    mid = ( l + r ) / 2;
    if( t == S[mid] ) {
      return 1;
    }
    if( t > S[mid] ){
      l = mid + 1;
    }
    else if( t < S[mid] ) {
      r = mid;
    }
  }
  return 0;
}

