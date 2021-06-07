#include<stdio.h>
#define N 1000000

int binarySearch(int S[], int key, int n){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key) return 1;
    if(key > S[mid]) left = mid + 1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}

int main(){
  int i, n, S[N], q, key, cont = 0;

  scanf("%d", &n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for( i = 0 ; i < q ; i++ ){
    scanf("%d", &key);
    if( binarySearch(S, key, n) ) cont++;
  }
  printf("%d\n", cont);
  return 0;
}

