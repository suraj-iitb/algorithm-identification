#include <stdio.h>
#include <stdlib.h>

int linearSearch(int );
#define N 10000
#define Q 500
#define true 1
#define fault 0

int S[N], n;

int main(){
  int T[Q];
  int q, i, hantei, count=0;

  scanf("%d", &n);
  if(n > N) exit(1);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
    if(S[i] < 0 || S[i] > 1000000000) exit(2);
  }

  scanf("%d", &q);
  if(q > Q) exit(3);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
    if(T[i] < 0 || T[i] > 1000000000) exit(4);

    hantei = linearSearch( T[i] );
    if(hantei == 1) count++;
  }

  printf("%d\n",count);


  return 0;
}

int linearSearch(int x){
  int i;

  for(i=0; i<n; i++){
    if( S[i] == x) return true;
  }
  return fault;
}



