#include<stdio.h>
#define SWAP(a,b) (a += b,b = a - b,a -= b)
int main (){
  int a,A[100]={},flag,count=0;
  scanf("%d",&a);
  for(int i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag==1){
    flag=0;
    for(int i=a-1;i>0;i--){
      if(A[i-1]>A[i]){
	SWAP(A[i-1],A[i]);
	flag=1;
	count++;
      }
    }
  }
    for(int i=0;i<a-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[a-1]);
    printf("\n%d\n",count);
  return 0;
}

