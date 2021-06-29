#include <stdio.h>
#include <stdlib.h>

int main(){

  int i,j,k;
  int num,key;
  int *A;
  
  scanf("%d",&num);
  A=malloc(sizeof(int)*num);

  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<num-1;i++){
    printf("%d ",A[i]);
  }
  
    printf("%d\n",A[num-1]);
  
  for(i=1;i<num;i++){
    key=A[i];
    j=i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j]; 
      j--;
      A[j+1] = key;
    }
    for(k=0;k<num-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[num-1]);
  }
  free(A);
  
  return 0;
}
