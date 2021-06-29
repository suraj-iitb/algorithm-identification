#include<stdio.h>
#define N 100
int main(void){
  int A[N],i,j,n;
  int t,count=0;
  int flag;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  flag = 1;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
        count++;
        flag = 1;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
}
