#include <stdio.h>
#define N 100

void selectionSort(int *,int);

int k=0;

int main(){
  int i,n,A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",k);
  return 0;
}

void selectionSort(int *A,int n){
  int i,j,minj,s;
  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(minj!=i){
      s=A[i];
      A[i]=A[minj];
      A[minj]=s;
      k++;
    }
  }
}


