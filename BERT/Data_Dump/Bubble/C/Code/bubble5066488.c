#include<stdio.h>

void bubbleSort(int A[],int N);
int cnt;

int main(){
  int i,key,flag=0,N;
  int A[100];
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
    
  bubbleSort( A, N);

  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n%d\n",cnt);
  
  return 0;
}

void bubbleSort(int A[],int N){
  int j,key,flag=1;

  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	key=A[j-1];
	A[j-1]=A[j];
	A[j]=key;
	flag=1;
	cnt++;
      }
    }
  }
}

    

