#include<stdio.h>
#define M 100

void selectionSort(int *A,int N){

  int i,j,k,mini,count=0;

  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(A[j] < A[mini]) {
	mini = j;
      }
    }
    if(mini != i) count ++;
    k = A[i];
    A[i] = A[mini];
    A[mini] = k;

  }
  for(i=0;i<N;i++){
    if(i==N-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

}

int main(){

  int i,j,k,A[M];

  scanf("%d",&k);

  for(i=0;i<k;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,k);

  return 0;
}

