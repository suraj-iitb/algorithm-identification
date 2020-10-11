#include <stdio.h>
int main() {

  int A[100],minj,i,j,x,N,count=0,flag;

  scanf("%d",&N);
  for(i = 0; i < N; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N; i++) {
    minj = i;
    flag = 0;
    for(j = i; j < N; j++) {
      if(A[j] < A[minj]) {
	minj = j; /*最小値があったらその位置を記憶するための動作*/
	flag = 1; /*for文で確かめるなかで、最小値が変わったらflagを1にする。*/
	
      }
    }
    if(flag == 1) {
      x = A[i];
      A[i] = A[minj];
      A[minj] = x;
      count++; /*交換回数を表す。*/
    }
  }

  for(i = 0; i < N; i++) {
    printf("%d",A[i]);
    if(N-1 != i) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
} 
