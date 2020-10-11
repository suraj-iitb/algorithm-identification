#include<stdio.h>

void selectionSort(int A[101],int N){
  int t,c=0,minj;

  for(int i=0;i<N;i++){
    minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    if(i != minj)c++;
  }
  for(int i=0;i<N;i++){
    if(i==N-1){
    printf("%d\n",A[i]);
    break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",c);

}


int main(void){
  int n,A[101]={};
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);


  return 0;
}

