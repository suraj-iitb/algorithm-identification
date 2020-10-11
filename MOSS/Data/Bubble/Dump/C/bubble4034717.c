#include<stdio.h>
#define N 100

int main(){
  int n,i,j,k,flag,count = 0,A[N];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  j = 1;

  while(flag){
    flag = 0;
    for(i = n-1;i >= j;i--){
      if(A[i] < A[i-1]){
        flag = 1;
        k = A[i];
        A[i] = A[i-1];
        A[i-1] = k;
        count++;
      }
      /*for(k = 0;k < n;k++){
        printf("%d ",A[k]);
      }printf("\n");*/
    }
    j++;
  }
  for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i == n-1) break;
    printf(" ");
  } printf("\n");
  printf("%d\n",count);
  return 0;
}

