#include <stdio.h>

int main(void){

  int A[100];
  int i,j,k,n,flag = 1,x = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  while(flag != 0){

    flag = 0;

    for(j=n-1;j>0;j--){
      if(A[j] < A[j - 1]){
	k = A[j];
	A[j] = A[j - 1];
	A[j - 1] = k;
	x++;
	flag = 1;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i == n-1){
      printf("%d",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("\n%d\n",x);
  return 0;
}
