#include <stdio.h>
int main(){
  int N,A[100],i,j,flag=1,count=0,temp;
  scanf("%d",&N);
  for(i=0;i<N;i++)
	scanf("%d",&A[i]);
  while(flag){
	flag = 0;
	for(j=N-1;1<=j;j--){
	  if(A[j]<A[j-1]){
		temp=A[j-1];
		A[j-1]=A[j];
		A[j]=temp;
		flag=1;
		count++;
	  }
	}
  }
  for(i=0;i<N;i++){
	printf("%d",A[i]);
	if(i == N-1){
	  printf("\n");
	  break;
	}
	printf(" ");
  }
  printf("%d\n",count);
  return 0;
}

