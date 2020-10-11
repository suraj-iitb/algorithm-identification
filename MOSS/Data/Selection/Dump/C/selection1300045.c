#include <stdio.h>

int main(void){

  int A[100];
  int i,j,k,n,minj,x=0,flag=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj = i;
      flag = 0;
    for(j=i;j<n;j++){
      if(A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    if(flag == 1)
      x++;
    k = A[i];
    A[i] = A[minj];
    A[minj] = k;
  }

  for(i=0;i<n;i++){
    if(i == n - 1){
      printf("%d\n",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",x);
  return 0;
}
