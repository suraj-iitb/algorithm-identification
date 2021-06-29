#define N 100

#include <stdio.h>

int main(){
  int i,j,key,A[N],n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }  
  
  for(i=1;i<n;i++){

    for(j=0;j<n;j++){
      printf("%d",A[j]);
      if(j!=n-1) printf(" ");
    }
    printf("\n");
    
    key=A[i];
    j=i-1;
    
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }

  }
  
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j!=n-1) printf(" ");
  }
  printf("\n");  
  
}
    
    

