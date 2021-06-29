#include<stdio.h>
int main(){
  int A[100],i,j,N,b,c,count=0,flag;
  flag = 1;
  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  while(flag == 1){
    flag = 0;   
    for(j = N-1; j >= 1; j--){
      if(A[j] < A[j-1]){
	c = A[j];
	b = A[j-1];
	A[j-1] = c;
	A[j] = b;
	flag = 1;
	count++;
      }
    }
  }
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
  return 0;
}
