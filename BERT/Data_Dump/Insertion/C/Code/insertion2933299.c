#include<stdio.h>

int main(){
  int a,count=0;
  int v=0;
  int i=0;
  int n=0;
  int j=0;
  int k=0;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<n;i++){
    for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);
    v=A[i];
    j=i-1;
    while(j>=0 && A[j] > v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }
  for(k=0;k<n-1;k++){
    printf("%d ",A[k]);

  }
  printf("%d\n",A[n-1]);

  return(0);
}

