#include<stdio.h>
int main(){
  int i=0,j=0;
  int N=0;
  int A[1000];
  int count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  count=bbsort(A,N);
  if(N>1){
    for(i=0;i<N;i++){
      if(i<N-1){
	printf("%d ",A[i]);
      }
      if(i==N-1){
	printf("%d",A[i]);
      }
    }
    printf("\n");
    printf("%d\n",count);
  }
  else {
    for(i=0;i<N;i++){
      printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
  }
  return 0;
}
int bbsort(int A[],int N){
  int i=0,j=0;
  int temp=0;
  int count=0;
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
    }
  }
  return count;
}

