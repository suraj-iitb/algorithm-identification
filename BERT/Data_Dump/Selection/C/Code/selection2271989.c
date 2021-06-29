#include<stdio.h>
#define N 100

int main(){
  int i, j, minj, temp, flag = 0, s, t = 0;
  int A[N];

  scanf("%d",&s);
  for(i = 0; i < s; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < s; i++){
    minj = i;
    for(j = i; j < s; j++){
      if(A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(flag == 1){
      t++;
      flag = 0;
    }
  }

  for(i = 0; i < s; i++){
    printf("%d",A[i]);
    if(i != s - 1) printf(" ");
  }
  printf("\n%d\n",t);

  return 0;
}
