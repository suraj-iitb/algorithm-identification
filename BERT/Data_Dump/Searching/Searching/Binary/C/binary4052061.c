#include <stdio.h>

int judge(int *, int);

int n;

int main(){
  int q, S[100000], T[50000];
  int i, cnt = 0;


  scanf("%d", &n);

  for(i= 0; i < n; i++){
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
  int  left, right, mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right) / 2;

    if(A[mid] == key)     return 1;

    else if(key < A[mid]) right = mid;

    else                  left = mid + 1;
  }

  return 0;
}

