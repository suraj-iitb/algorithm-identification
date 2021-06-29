#include<stdio.h>
#define MAX 10000
#define NOT_FOUND -1

int linear(int *A, int key, int n){
  int i = 0;
  A[n] = key;

  while(A[i] != key){
    //printf("A[i](%d) and key(%d) is different!\n", A[i], key);
    i++;
    if(i == n) return NOT_FOUND;
  }
  return A[i];
}

int main(){
  int i, n_S, n_T, cnt=0, find;
  int S[MAX], T[MAX];

  scanf("%d", &n_S);
  for(i=0; i<n_S; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &n_T);
  for(i=0; i<n_T; i++){
    scanf("%d", &T[i]);
  }
  for(i=0; i<n_T; i++){
    if(linear(S, T[i], n_S-1) != NOT_FOUND){
      //printf("find!____%d\n", linear(S, T[i], n_S));
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}

