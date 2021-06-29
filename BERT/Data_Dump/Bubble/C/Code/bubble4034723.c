#include <stdio.h>


int main(){
  int len, i, flag, temp, cnt = 0;
  int A[100];

  scanf("%d", &len);

  for(i = 0; i < len; i++){
    scanf("%d", &A[i]);
  }


  flag = 1;

  while(flag){
    flag = 0;

    for(i = len - 1; i > 0; i--){
      if(A[i] < A[i-1]){
	temp = A[i];
	A[i] = A[i-1];
	A[i-1] = temp;
	cnt++;
	flag = 1;
      }
    }
  }

  for(i = 0; i < len - 1; i++){
    printf("%d ", A[i]);
  }

  printf("%d\n%d\n", A[len - 1], cnt);


  return 0;
}

