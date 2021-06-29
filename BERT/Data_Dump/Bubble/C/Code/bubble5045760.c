#include<stdio.h>
#define N 100

int main(){
  int n, i, A[N], temp, cnt = 0;
  int flag = 1;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(flag){
    flag = 0;
    for(i = n - 1; i>= 1; i--){
      if(A[i] < A[i-1]){
          temp = A[i];
          A[i] = A[i-1];
          A[i-1] = temp;
          flag = 1;
          cnt++;
        }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i == n - 1)break;
    printf(" ");
  }

  printf("\n%d\n", cnt);
  return 0;
}
