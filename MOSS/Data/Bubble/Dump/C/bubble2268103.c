#include <stdio.h>

void bubbleSort(int *,int);

int main(){

  int N,i;
  int A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  bubbleSort(A,N);
  
  return 0;

}

void bubbleSort(int A[],int N){
  int flag=1,i,j,tmp,n=0;

  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]) {
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	n++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",n);
  
}

  

  
