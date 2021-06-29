#include<stdio.h>

int selectionSort(int[],int);

int main(){
  int A[100];
  int i,n,count;

  scanf("%d",&n);
  if(n>=1&&n<=100){
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
  
  count=selectionSort(A,n);

  for(i=0;i<n;i++) {
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  }
}


int selectionSort(int A[],int N){
  int i,j,minj,num,count=0;

  for(i=0;i<N-1;i++) {
    minj = i;  
    for(j=i+1;j<N;j++) {
      if(A[j] < A[minj]) {
	minj = j;
      }  
    }    
    num = A[minj];
    A[minj] = A[i];
    A[i] = num;
    
    if(i!=minj){
      count++;
    }
  }
 
  return count;
}

