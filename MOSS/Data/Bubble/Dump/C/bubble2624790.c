#include<stdio.h>
int main(void){
  int n,i=0,k=0,j=0,flag,temp;
  int A[1000000];
  scanf("%d",&n);
  while(scanf("%d ",&A[i])==1){
    i++;
  }
  flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
        k++;
        temp=A[j];
        A[j]=A[j-1];
        A[j-1]=temp;
        flag=1;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",k);
}
