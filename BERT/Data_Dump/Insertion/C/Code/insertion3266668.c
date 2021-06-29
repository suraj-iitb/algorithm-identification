#include<stdio.h>
void insertionSort(int *,int);
int main(){
  int n;
  int i;
  int A[101];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  insertionSort(A,n);

  return 0;
}

void insertionSort(int A[],int N){
  int i,j,key,k;
  for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k!=N-1) printf(" ");
  }
  printf("\n");
  for(j=1;j<N;j++){
    key=A[j];
    i=j-1;
    while(i>=0 && key < A[i]){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k!=N-1) printf(" ");
    }
    printf("\n");
  }
}
  

