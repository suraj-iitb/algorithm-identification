#include<stdio.h>

int main(){
  int N,i,j,count=0,flag,temp;
  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  i=0;
  while(flag){
    flag = 0;
    for(j=N-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag =1;
	count = count + 1;
      }
    }
    i++;
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1){
      printf(" ");
  }
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}
	

  

