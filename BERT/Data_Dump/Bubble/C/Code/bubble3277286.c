#include<stdio.h>
#define N 100
int main(){
  int A[N];
  int i,n,flag,x,count=0,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  j = 0;
  flag = 1;
  while(flag){
    flag = 0;
    for(i=n-1;i>=j+1;i--){
      if(A[i]<A[i-1]){
	x = A[i];
	A[i] = A[i-1];
	A[i-1] = x;
	flag = 1;
	count++;
      }
    }
    j++;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

