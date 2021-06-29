#include <stdio.h>
void insertionSort(int [],int);
void printArray(int [],int );
int main(){
  int i,j,A[100],n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  printArray(A,n);
  insertionSort(A,n);

  return 0;
}


  void insertionSort(int A[],int N){
    int i,j,v;
    for(i=1;i<N;i++){
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v){
        A[j+1]=A[j];
        A[j]=v;
        j--;
      }
      printArray(A,N);
  }
}

void printArray(int A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
printf("\n");
}
