#include<stdio.h>

#define true 1
#define false 0

int linearSearch(int A[], int key, int n){
  int i;

  for(i = 0; i < n; i++){
    if(A[i] == key){
      return true;
    }
  }
  return false;
}

int main(){
  int S[10000], T[500];
  int i, n, q;
  int count = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){
    if(linearSearch(S, T[i], n) == true){
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}

