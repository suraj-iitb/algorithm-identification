#include <stdio.h>

void insertionSort(int *,int);

int main(){
  int i,N,A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
  printf("%d",A[i]);
  if(i<N-1)printf(" ");
  }
  printf("\n");
  insertionSort(A,N);
  return 0;
}

void insertionSort(int a[],int n){
  int i,j,k,v;
  
  for(i=1;i<=n-1;i++){
    v=a[i];
    j=i-1;
    
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k<n-1)printf(" ");
    }
    printf("\n");
  }
}


