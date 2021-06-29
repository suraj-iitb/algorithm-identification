#include <stdio.h>

int bubbleSort(int *, int);

int main(){
  int A[100];
  int N,sw,i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  sw = bubbleSort(A, N);

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
  }
  
  printf("\n");
  printf("%d\n",sw);
  
  return 0;
}

int bubbleSort(int A[], int N){
  int i=0,j,temp,sw,flag;
  flag=1;
  sw=0;
  while(flag){
    flag=0;
    for(j=N-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag=1;
	sw++;
      }
    }
  }
  return sw;
}

