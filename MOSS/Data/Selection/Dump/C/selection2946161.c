#include<stdio.h>

void selectionSort(int *A, int N);

int main(void){

  int i;
  int A[100],n;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  selectionSort(A, n);

  return 0;
}

void selectionSort(int *A, int N){

  int i,j;
  int minj,tmp,hit;
  int cnt=0;

  for(i=0;i<N;i++){
    minj=i;
    hit=0;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
	hit=1;
      }
    }
  
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(hit==1)cnt++;
  }
  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
}

