#include <stdio.h>
#define N 100
int main(void){
  int i, j, n, temp, A[N];
  int flag, cnt = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
       scanf("%d",&A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j = n-1; j >= 1; j--){
      if(A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        cnt++;
        flag = 1;
      }
    }
  }


  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
        }
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);

}

