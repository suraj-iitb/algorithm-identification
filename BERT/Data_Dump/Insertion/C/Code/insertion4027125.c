#include <stdio.h>

void output(int A[],int N)
{
  int i;
  for(i=0; i<N ;i++){
    printf("%d",A[i]);
    if(i==N-1){
    printf("\n");
    }else {
    printf(" ");
    }
  }
}


void insertionSort(int A[], int N)
{
  int i,j,v;
  for(i=1; i<N ; i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j] >v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    output(A,N);
  }
}


int main(){
  int N,i,j,v;
  scanf("%d",&N);

  int A[N];
  for(i=0; i<N ;i++){
    scanf("%d",&A[i]);
  }
    output(A,N);
    insertionSort(A,N);
  return 0;
}



