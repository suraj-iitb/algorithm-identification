#include<stdio.h>

int main(){

  int i,j=0,l,n,status ,v=0;
  int A[100];

  scanf("%d",&n);
  i=0;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while (j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] =v;

    for(l=0;l<n-1;l++){
      printf("%d ",A[l]);
    }
    printf("%d",A[n-1]);
    printf("\n");
  }
  return 0;
}

