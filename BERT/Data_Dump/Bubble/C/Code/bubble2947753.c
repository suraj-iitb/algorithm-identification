#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,w,tmp;
  int *A;
  int n,count=0;

    scanf("%d",&n);

  
  A = (int *)malloc(n * sizeof(int));
  

  
  for(i=0; i<n ; i++){
    scanf("%d",&A[i]);
      }

  for(i=0; i<(n-1) ; i++){
    
    for(j=(n-1); j>i ; j--){
      
      if(A[j-1] > A[j]){
      tmp=A[j-1];
      A[j-1] = A[j];
      A[j] = tmp;
      count++;
    }
  }
}

  
  for(w=0; w<n ; w++){

    if(w==n-1){
      printf("%d\n",A[w]);
      break;
    }
    
      printf("%d ",A[w]);
  
}


  printf("%d\n",count);
  
  return 0;
}

