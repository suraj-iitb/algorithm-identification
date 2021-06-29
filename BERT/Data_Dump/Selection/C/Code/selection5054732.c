#include <stdio.h>
#define N 100
int main(void){
  int A[N], i, j, n, minj, temp, cnt = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
  scanf("%d",&A[i]);
  }

  for(i = 0; i < n-1; i++){
    minj = i;
    for(j = i; j <= n-1; j++){
      if(A[j] < A[minj]){
          minj = j;
      }
    }
    if(minj != i){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    cnt++;
    }
  }

  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
        }
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);

}

