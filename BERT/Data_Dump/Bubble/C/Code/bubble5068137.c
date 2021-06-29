#include <stdio.h>

int bubbleSort (int *,int);

int main(){
  int A[100],N,i,sw;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  sw=bubbleSort(A,N);

  for(i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;
}

int bubbleSort(int A[], int N)
{
  int i,j,t,sw=0;

  for (i=0;i<N-1;i++){
    for (j=N-1;j>i;j--){
      if (A[j-1]>A[j]){
        t=A[j-1];
        A[j-1]=A[j];
        A[j]=t;
    if(i!=j) sw++;
      }
    }
  }
  return sw;
}
