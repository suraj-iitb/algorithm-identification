#include<stdio.h>
void selectionSort(int *,int);
int cnt=0;
int main(){
  int N;
  int i;
  int A[101];
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  selectionSort(A,N);
  printf("%d\n",cnt);
  return 0;
}

void selectionSort(int A[],int N){
  int i,j,minj,tmp;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[minj]>A[j]){
	minj=j;
      }
    }
    if(i!=minj) cnt++;
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
}
  

