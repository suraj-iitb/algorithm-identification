#include<stdio.h>

int main(void){
  int A[100],n,i,j,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<n;i++){
    for(j=0;j<n-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d",A[n-1]);
    printf("\n");
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
     }
    A[j+1] = v;
  }
  for(i=0;i<n-1;i++){
      printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");
}



