#include<stdio.h>

#define N 100

int main(){
  int a,i,j,count = 0;
  int A[N+1];
  int flag,k;

  scanf("%d",&a);

  for(i = 1;i <= a;i++){
    scanf("%d",&A[i]);
  }
  flag = 1;
  i = 1;
  while(flag){
    flag = 0;
    for (j = a;j >= i + 1;j--){
      if(A[j] < A[j - 1]){
        k = A[j];
	A[j] = A[j - 1];
	A[j - 1] = k;
	count++;
	flag = 1;
      }
    }
    i++;
  }
  for(i = 1;i <= a;i++){
    if(i == a){
      printf("%d",A[i]);
    }
    else
    printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

