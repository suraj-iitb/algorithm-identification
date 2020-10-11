#include<stdio.h>

void insertionSort(int A[],int N){
  int v,k,i,j;
  for(i=0;i<N;i++){
    v = A[i];
    j = i - 1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k!=N-1) printf(" ");

    }
    printf("\n");
  }
  
  
}


int main(void){
  int i,v,n;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  return(0);
}
