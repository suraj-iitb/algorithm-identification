#include<stdio.h>
#define N 10000
#define Q 500
#define NOT_FOUND 0

int linearSearch(int*, int*, int, int);

int main(){
  int n, q, i, j, A[N], B[Q], cnt = 0, key, loop;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &B[i]);
  }

  for(i = 0; i < q; i++){
    cnt += linearSearch(A, B, n, i);
  }

  printf("%d\n", cnt);

  return 0;
}

int linearSearch(int* A, int* B, int n, int k){
  int i = 0, key;
  key = B[k];
  A[n] = key;
  while(A[i] != key){
    i++;
  }
  if(i == n){
    return NOT_FOUND;
  }
  return 1;
}
