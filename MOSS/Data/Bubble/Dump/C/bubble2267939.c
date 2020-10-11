#include<stdio.h>

#define N 100

int main(){
  int A[N];
  int i,a,min, count = 0;
  int flag = 1;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag=0;
    for(i=a-1;i>0;i--){
      if(A[i]<A[i-1]){
	min = A[i];
	A[i]=A[i-1];
	A[i-1] = min;
	flag = 1;
	count += 1;
      }
    }
  }

  for(i=0;i<a-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[a-1]);
  printf("%d\n",count);
  return 0;
}
