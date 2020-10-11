#include <stdio.h>

#define N 100

int main(){
  int inp, i, j, flag=1, temp, cha=0;
  int A[N];
  
  scanf("%d", &inp);
  for(i = 0; i < inp; i++){
    scanf("%d", &A[i]);
  }
  while(flag == 1){
    flag = 0;
    for(j = inp-1; j > 0; j--){
      if(A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        flag = 1;
        cha++;
      }
    }
  }
  for(i = 0; i < inp-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d", A[i]);
  
  printf("\n%d\n", cha);
  return 0;
}

