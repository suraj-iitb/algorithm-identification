#include<stdio.h>

#define FOUND '1'
#define NOT_FOUND '0'

int linearSearch(int [1000000], int, int);

int main(){
  int i, n, q, count = 0;
  int S[1000000], T[1000000];

  scanf("%d",&n);

  for(i = 0; i < n; i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i = 0; i < q; i++) scanf("%d",&T[i]);
  
  for(i = 0; i < q; i++){
    if(linearSearch(S, T[i], n) == FOUND) count++;
  }
  
  printf("%d\n",count);

  return 0;
}

int linearSearch(int A[], int key, int n){
  int i = 0;

  A[n] = key;

  while(A[i] != key){
    i++;
  }

  if(i == n) return NOT_FOUND;
  else return FOUND;
}
