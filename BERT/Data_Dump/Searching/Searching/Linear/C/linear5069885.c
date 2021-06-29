#include <stdio.h>
int linearSearch(int, int *, int);
int main(){
  int n, q, i, x, a = 0;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  for(i = 0; i < q; i++){
  x = linearSearch(n, S, T[i]);
  a += x;
  }
  printf("%d\n", a);
  return 0;
}
int linearSearch(int n, int A[], int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key){
    i++;
  }
  if(i == n) return 0;
  return 1;
}
