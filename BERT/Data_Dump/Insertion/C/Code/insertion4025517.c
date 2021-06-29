#include<stdio.h>
#define N 100

int main(){
  
  int i,v,j,k,A[1000],n;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
  for(i=0;i<n;i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
      
    }
    
    for(k=0;k<n;k++){
    printf("%d",A[k]);
    if(k!=n-1)printf(" ");
    
  }
    printf("\n");
    
  }
  
  return 0;
}

