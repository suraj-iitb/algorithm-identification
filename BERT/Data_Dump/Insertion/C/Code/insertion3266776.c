#include<stdio.h>
#define MAX 100

int main(){
  int i,j,k,v,n,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<n;k++){
      if(k) printf(" ");
      printf("%d",A[k]);
      
    }
    printf("\n");
  }
  return 0;
}

