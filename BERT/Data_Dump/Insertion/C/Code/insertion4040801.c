#include <stdio.h>
#define N 100

void insertionSort(int*, int);

int main(){
  int i,A[N],n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  insertionSort(A,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i==n-1)break;
    printf(" ");
  }
  printf("\n");
  return 0;
}

void insertionSort(int* A, int n){
  int i,j,v,k;
  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k==n-1)break;
      printf(" ");
    }
    printf("\n");
  
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }
}

