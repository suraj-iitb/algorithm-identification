#include<stdio.h>

int selectionSort(int A[], int N);

int main(){
  int N,i,cnt;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  cnt=selectionSort(A,N);

  for(i=0;i<N;i++){
    if(i>0 && i<N) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

int selectionSort(int A[],int N){
  int i,j,a,minj,cnt=0;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
    if(i!=minj) cnt++;
  }
  return cnt;
}

