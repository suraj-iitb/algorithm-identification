#include<stdio.h>

void selectionSort(int A[],int N);
int count=0;
int main()
{
  
  int i;
  int A[100],N;
  
  scanf("%d",&N);
  for(i=0;i<N;++i){
    scanf("%d",&A[i]);
  }
  
  selectionSort(A,N);
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

void selectionSort(int A[], int N)
{
  int i,j,minj,temp,flag = 0;
  
  for(i=0;i<N;i++){
    minj=i;
    flag = 0;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
	flag = 1;
      }
    }
    if(flag==1){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
    }
    
  }
  
}
