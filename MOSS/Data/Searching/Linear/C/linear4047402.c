#include<stdio.h>

#define  N 10000

int  search(int A[], int n, int key){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( A[i] == key ) return 1;
  }
  return 0;
}

int main(){
  int n, i, q, key, cnt=0;
  int A[N];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  scanf("%d", &q);

  for ( i = 0; i < q; i++ ) {
    scanf("%d", &key);
    cnt +=search(A,n,key);
  }
  printf("%d\n",cnt);
  
  return 0;
}
