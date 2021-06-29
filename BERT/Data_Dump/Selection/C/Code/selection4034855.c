#include <stdio.h>

int main(){
  int len, i, j, minj, temp, cnt = 0;
  int A[100];

  scanf("%d", &len);

  for(i = 0; i < len; i++){
    scanf("%d", &A[i]);
  }


  for(i = 0; i < len; i++){
    minj = i;

    for(j = i; j < len; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }

    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(i != minj) cnt++;
  }

  for(i = 0; i < len - 1; i++){
    printf("%d ", A[i]);
  }

  printf("%d\n%d\n", A[len-1], cnt);

  return 0;
}

