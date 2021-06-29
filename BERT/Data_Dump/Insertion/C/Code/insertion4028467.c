#include <stdio.h>
#define N 100

int main(){

  int i,j,k,A[N],length,v;

  scanf("%d",&length);
  
  for(i=0;i<length;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<length;i++){
    if(i==length-1)printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  
  for(i=1;i<length;i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(k=0;k<length;k++){
      if(k==length-1)printf("%d",A[k]);
      else printf("%d ",A[k]);
    }
    printf("\n");
  }
  return 0;
}


