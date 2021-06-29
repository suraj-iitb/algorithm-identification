#include <stdio.h>

void bubbleSort(int[],int);

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
  int flag,j,a,i,n,count=0;

  flag = 1; 
  i = 0;

  while(flag){
    flag = 0;
    
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	flag = 1;
	count++;
      }
    }  
    i++;
  }
  for(n=0;n<N;n++){
    if(n>0)printf(" ");
      printf("%d",A[n]);
    }
    printf("\n");
    printf("%d\n",count);
}
     

