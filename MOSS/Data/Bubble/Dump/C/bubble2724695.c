#include <stdio.h>
int main(){
  int num;
  scanf("%d", &num);
  int i, j;
  //データの入力
  int A[100];
  for(i=0; i<num; ++i){
	scanf("%d", &A[i]);
  }
  int count=0;
  int tmp;
  for(i=0; i<(num-1); ++i){
	for(j=(num-1); j>i; --j){
	  if(A[j-1]>A[j]){
		tmp=A[j-1];
		A[j-1]=A[j];
		A[j]=tmp;
		++count;
	  }
	}
  }
  //出力
  for(i=0; i<num; ++i){
	printf("%d", A[i]);
	if(i<(num-1))
	  printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}

