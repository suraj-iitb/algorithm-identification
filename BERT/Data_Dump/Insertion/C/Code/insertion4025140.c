#include <stdio.h>
#include <stdlib.h>

/*void insertionSort(int *A, int N){ // N個の要素を含む0-オリジンの配列A
  int i,j,keep,k;
  for(i=1;i <= N-1;i++){
    keep = A[i];
    j = i - 1;
    while(j>= 0 && A[j] > keep){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = keep;
    for(k=0;k<N;k++){
      if(k>0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }
  }*/

int main(){
  int array[1000],i=0,n,keep,k,j;
  scanf("%d",&n);
  if(n<0 || n>100) exit(2); 
  for(i=0;i<n;i++) scanf("%d",&array[i]);
  for(k=0;k<n;k++){
    if(k>0) printf(" ");
    printf("%d",array[k]);
  }
  printf("\n");
  //insertionSort(array,n);
  for(i=1;i <= n-1;i++){
    keep = array[i];
    j = i - 1;
    while(j>= 0 && array[j] > keep){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = keep;
    for(k=0;k<n;k++){
      if(k>0) printf(" ");
      printf("%d",array[k]);
    }
    printf("\n");
  }
  
  return 0;
}

