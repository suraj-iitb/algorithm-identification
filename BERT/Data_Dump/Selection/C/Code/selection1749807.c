#include<stdio.h>

void selectionSort(int *,int );

int main(){

  int A[100];

  int N;

  int i;

  scanf("%d",&N);

  for(i=0;i<N;i++){

    scanf("%d",&A[i]);

  }

  selectionSort(A,N);

  return 0;
}

void selectionSort(int *A,int N){

  int i,j,min,cnt=0,temp;

  for(i=0;i<=N-1;i++){

    min=i;

    for(j=i;j<=N-1;j++){
      
      if(A[j]<A[min]){

	min = j;

      }

    }

    if(A[i]!=A[min]){

      temp=A[i];
      A[i]=A[min];
      A[min]=temp;
      cnt++;
  }

  }

  for(j=0;j<N;j++){

    if(j==N-1)printf("%d\n",A[j]);

    else printf("%d ",A[j]);

  }

  printf("%d\n",cnt);

}
