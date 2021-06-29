#include <stdio.h>
#define N 100

int main(){
  int A[N];
  int num, i, temp;
  int count = 0, flag = 1;

  scanf("%d", &num);
  
  for(i = 0; i < num; i++){
    scanf("%d", &A[i]);
  }

  while(flag == 1){
    flag = 0;
    for(i = num-1; i > 0; i--){
      if(A[i] < A[i-1]){
	temp = A[i];
	A[i] = A[i-1];
	A[i-1] = temp;

	flag = 1;
	count++;
      }
    }
  }
  for(i = 0; i < num-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num-1]);
  printf("%d\n",count);
  return 0;
}

