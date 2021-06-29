#include <stdio.h>

int main(){
  
  int i,n,v,j,m;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(i=0;i<n;i++){
    
    printf("%d",A[i]);
    
    if(i<n-1)printf(" ");
    
  }
  
  printf("\n");
  
  for(i=1;i<n;i++){
    
    v=A[i];
    
    j=i-1;

    while(j>=0 && A[j]>v){
      
      A[j+1] = A[j];
      
      j--;
      
      A[j+1] =v;
      
    }
    
    for(m=0;m<n;m++){
      
      printf("%d",A[m]);
      
      if(m<n-1)printf(" ");
      
    }
    
    printf("\n");
    
  }
      
  return 0;  
}

