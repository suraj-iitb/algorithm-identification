#include<stdio.h>

#define N 100

int main(){
  int n;
  int A[N],v;
  int i,j,k;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  for(i=1;i<n;i++){
    for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);
    
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }
  for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
      
    }
  printf("%d\n",A[n-1]);
  return 0;
}

