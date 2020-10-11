#include<stdio.h>

int main(){
  int A[100],i,n,flag,count,key;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);

  flag = 1;
  count = 0;

  while(flag){
    flag = 0;

    for(i = n-1; i > 0; i--){
      if(A[i] < A[i-1]){
	key = A[i-1];
	A[i-1] = A[i];
	A[i] = key;
	count++;
	flag = 1;
      }
    }

  }
	
  for(i = 0; i < n-1; i++)
    printf("%d ",A[i]);

  printf("%d\n",A[n-1]);

  printf("%d\n",count);

  return 0;
}
