#include<stdio.h>

int main(){

  int flag,A[100],i,j,k,a,count = 0;

  scanf("%d",&a);

  for(i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }

  flag = 1;

  while(flag){
    flag = 0;
    for(j = a - 1; j > 0; j--){
      if(A[j] < A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0; i < a; i++){
    printf("%d",A[i]);
    if(i == a -1) break;
    printf(" ");
  }

  printf("\n");

  printf("%d\n",count);

  return 0;
}
