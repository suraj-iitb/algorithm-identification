#include<stdio.h>
int main(){
  int N=0,i=0,j=0,count=0;
  int A[10000];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  count=selsort(A,N);
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
int selsort(int A[], int N){
  int i=0,j=0,temp=0;
  int min=0;
  int count=0;
  for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
    if(i!=min)count++;
  }
  return count;
}

