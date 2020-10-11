#include <stdio.h>
int bubbleSort(int *,int);

int main(){
  int A[100],N;
  int i,count;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  count = bubbleSort(A,N);
  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
return 0;
}

int bubbleSort(int *A,int N){
  int j,temp,flag=1,count=0;
  while(flag){
    flag = 0;
    for(j=N-1; j>=1; j--){
      if(A[j]<A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	count++;
      }
    }
  }
  return count;
}
