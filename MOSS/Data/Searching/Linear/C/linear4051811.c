#include <stdio.h>

int judge(int*, int);

int n;

int main(){
  int q, S[10001], T[500];
  int i, cnt = 0;

  scanf("%d", &n);

  
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){
    cnt += judge(S, T[i]);
  }

  printf("%d\n", cnt);

  return 0;
  
}


int judge(int *A, int key){
  int i = 0;
  
  A[n] = key;

  while(A[i] != key) i++;
  
  if(i == n) return 0;

  return 1;
}

