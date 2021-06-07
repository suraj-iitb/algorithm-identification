#include <stdio.h>
#include <stdlib.h>

int binarySearch(int );
#define N 100000
#define Q 50000
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

    hantei = binarySearch( T[i] );
    if(hantei == 1) count++;
  }

  printf("%d\n",count);


  return 0;
}

int binarySearch(int x){
  int left=0, right=n, mid;

  while(left < right){
    mid = (left + right)/2;
    if ( S[mid] == x) return true;
    else if( x < S[mid]) right = mid;
    else left = mid +1;
  }

  return fault;
}

