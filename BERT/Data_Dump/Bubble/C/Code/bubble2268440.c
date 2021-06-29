#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int *,int);
void swap(int *, int *);

int main(){

  int i,j,n,*tmp;

  scanf("%d",&n);
  
  tmp = (int *)malloc( sizeof(int) * n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&tmp[i]);
  }

  bubbleSort(tmp,n);

  free(tmp);

  return 0;

}

void bubbleSort(int *A,int N){
  int i = 0,j,sum = 0;

  for(i = 0;i < N-1; i++){
    for(j = N-1;j >= i+1;j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	sum++;
      }
    }
    }
    

  for(i = 0;i < N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",sum);
}



void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
