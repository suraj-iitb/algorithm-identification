#include<stdio.h>
#define N 10000

int linearSearch(int S[], int key, int n){
  int i;
  for( i = 0 ; i < n-1 ; i++ ){
    if(S[i] == key) return 1;
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
    if( linearSearch(S, key, n) == 1 ) cont++;
  }
  printf("%d\n", cont);
  return 0;
}

