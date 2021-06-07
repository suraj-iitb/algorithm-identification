#include<stdio.h>

int linearSearch(int A[], int n, int key){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( A[i] == key ) return 1;
  }
  return 0;
}

int main(){
  int i, n, A[10000], q, key, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++){
    scanf("%d", &key);
    if (linearSearch(A, n, key)) sum++;
  }
  printf("%d\n", sum);
  return 0;
}
