#include <stdio.h>

int main(){

  int N,i,j,flag,temp=0,count=0;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }


  for(i=0;i<N;i++){

  flag = 1;

  while(flag){
    flag=0;
    for(j=N-1;1<=j;j--){
	if(A[j] < A[j-1]){
	  temp = A[j-1];
	  A[j-1] = A[j];
	  A[j] = temp;
	  flag=1;
	  count++;
	}

      }
  }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);


  return 0;
}
      
