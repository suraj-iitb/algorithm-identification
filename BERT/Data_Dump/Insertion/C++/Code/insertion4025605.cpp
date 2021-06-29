#include<stdio.h>

#define N 100

int main(){
  int A[N],i,j,v,b,k;

  scanf("%d",&b);
  
  for(i=0;i<b;i++){
    scanf("%d",&A[i]);
  }
  
  printf("%d",A[0]);
  for(i=1;i<b;i++){
    printf(" %d",A[i]);
  }
  printf("\n");

  for(i=1;i<=b-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    
    printf("%d",A[0]);
    for(k=1;k<b;k++){
      printf(" %d",A[k]);
    }
    printf("\n");
  }

  return 0;
}

