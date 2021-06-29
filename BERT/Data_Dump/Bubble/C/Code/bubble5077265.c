#include<stdio.h>

void swap(int *a,int *b)
{
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

void BubbleSort(int A[], int N){

  int i,j,sw=0;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        swap(&A[j],&A[j-1]);
        sw++;
      }
    }
  }

  for (i = 0; i < N-1; i++) {
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d",A[N-1]);

  printf("\n");
  printf("%d\n",sw);
}

int main(){
  int A[100],N,i,sw;

  scanf("%d",&N);

  for(i=0;i<N;i++) scanf("%d",&A[i]);

  BubbleSort(A,N);

  return 0;
}

