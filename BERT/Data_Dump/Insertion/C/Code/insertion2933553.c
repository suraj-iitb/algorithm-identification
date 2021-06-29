#include <stdio.h>
#include <stdlib.h>
int main(){
  int *A;
  int k=0,i=0,j=0,v=0,a,c=0,size;

  scanf("%d",&size);//size of array
  A = (int *)malloc(size * sizeof(int)); // memory

  for(c=0;c<size;c++){
  scanf("%d",&a);
    A[c]=a;
    }

  for(k=0;k<c-1;k++){
    printf("%d ",A[k]);
  }
  printf("%d",A[k]);
  printf("\n");
  

  for(i=1;i<=c-1;i++){
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  for(k=0;k<c-1;k++){
    printf("%d ",A[k]);
  }
  printf("%d",A[k]);
  // if(i<c-1)
    printf("\n");
  }
  free(A);
  return 0;
}

