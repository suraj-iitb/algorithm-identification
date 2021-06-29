#include <stdio.h>

int main(){
  int A[100],i,j,n,tmp,count=0;
  int flag = 1;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  while(flag == 1){
    flag = 0;
    for(i=n-1;i>=1;i--){
      if(A[i] < A[i-1]){
        tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flag = 1;
        count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}

