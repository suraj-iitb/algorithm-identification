#include<stdio.h>

int main(void){
  int A[100],n,i,j,temp,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
      printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",count);
}

