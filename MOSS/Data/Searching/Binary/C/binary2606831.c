#include<stdio.h>

int S[1000000], N, k = 0;

int binarySearch(int X){
  int left = 0;
  int right = N;
  int middle;
  
  while(left < right){
    middle = (left + right) / 2;
    if(X == S[middle]){
      return 1;
    }
    else if(X > S[middle]){
      left = middle + 1;
    }
    else {
      right = middle;
    }
  }
  return 0;
}

int main() {
  int M, i, x,count = 0 ;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &S[i]);
  }
  
  scanf("%d", &M);
  for(i = 0; i < M; i++){
      scanf("%d", &x);
      if(binarySearch(x) == 1){
        count += 1;
      }
  }
  
  printf("%d\n",count);
  
  return 0;
}
