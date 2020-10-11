#include<stdio.h>
int main(){
  int n,A[100],i,j,x,flag;
  int count;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  count=0;
    flag=1;
    i=0;
    while(flag){
      flag=0;
      for(j=n-1;j>=i+1;j--){
	if(A[j]<A[j-1]){
	  x=A[j];
	  A[j]=A[j-1];
	  A[j-1]=x;
	  flag=1;
	count++;
	}
      }
    }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

