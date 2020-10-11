#include<stdio.h>
#define N 100

int main(){
  int A[N],n,i,j,key,count=0,flag;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  while(flag==1){
    flag=0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	key=A[j];
	A[j]=A[j-1];
	A[j-1]=key;
	count++;
	flag=1;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}
  

