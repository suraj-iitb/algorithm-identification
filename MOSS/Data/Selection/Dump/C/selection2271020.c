#include<stdio.h>
void selectionSort(int*,int);
int main(){
  int array[100],N;
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&array[i]);
  selectionSort(array,N);
  return 0;
}
void selectionSort(int *A,int N){
  int i,j,minj,keep,count=0;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj=j;
    }
    if(minj!=i){
      keep=A[i];
      A[i]=A[minj];
      A[minj]=keep;
      count++;
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
}
