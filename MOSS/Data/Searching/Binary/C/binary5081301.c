#include<stdio.h>
#define N 100000
#define Q 50000
#define NOT_FOUND 0

int binarySearch(int*, int*, int, int);

int main(){
  int n, q, i, S[N], T[Q], cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){
    cnt += binarySearch(S, T, n, i);
  }

  printf("%d\n", cnt);

  return 0;
}

int binarySearch(int* S, int* T, int n, int key){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == T[key]){
      return 1;
    }
    else if(T[key] < S[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return NOT_FOUND;
}
