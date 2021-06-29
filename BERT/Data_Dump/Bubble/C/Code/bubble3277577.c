#include<stdio.h>
#define N 100

int main(){
  int j,n,i,count=0,flag,temp;
  int A[N];

  scanf("%d",&n);
  i=0;
  while(i<n){
    scanf("%d",&A[i]);
    if(A[i]>=0 && A[i]<=100)i++;
  }
  flag = 1;
  j=0;
  while(flag == 1){
    flag = 0;
    for(i=n-1; i > j; i--){
      if(A[i] < A[i-1]){
      temp = A[i];
      A[i] = A[i-1];
      A[i-1] = temp;
      flag = 1;
      count++;
      }
    }
      j++;
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

