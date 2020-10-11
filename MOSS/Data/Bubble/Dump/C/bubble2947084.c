#include <stdio.h>

int main(){
  int j;
  int N;
  int flag=1;
  int a;
  int count=0;

  scanf("%d",&N);
  int A[N];

  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }

  while(flag==1){
    flag=0;
    for(j=N-1;j>=0;j--){
      if(A[j] < A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	count++;
	flag=1;
      }

    }

  }

  for(j=0;j<N;j++){
    if(j==N-1){
      printf("%d\n",A[j]);
      printf("%d\n",count);
    }
    else printf("%d ",A[j]);
  }


  return 0;
}

