#include<stdio.h>
#define N 100
int main(){
  int n, i, j, minj, temp, A[N];
  int cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    temp = A[i];
    if(A[i] != A[minj])cnt++;
    A[i] = A[minj];
    A[minj] = temp;
  }

  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i == n - 1){
      break;
    }
    printf(" ");
  }
  printf("\n%d\n", cnt);

  return 0;
}
