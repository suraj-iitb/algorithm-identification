#include<stdio.h>
int main(){
  int N;
  scanf("%d",&N);
  int A[N];
  int i;

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  int count=0,j,temp;

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j-1]>A[j]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	count++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i != N - 1)printf("%d ",A[i]);
	else printf("%d", A[i]);  
}
  printf("\n");
  printf("%d\n",count);

  return 0;
}

