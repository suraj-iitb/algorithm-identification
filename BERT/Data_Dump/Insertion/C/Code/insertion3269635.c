#include <stdio.h>


int main(){
  int N;
  int i,j,k,v;
  int A[1001];
  
  
  
  
  scanf("%d",&N);
   
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(k=0;k<N;k++){
    if(k==N-1){
      printf("%d\n",A[k]);
    }else
      printf("%d ",A[k]);

  }
  
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<N;k++){
      if(k==N-1){
	printf("%d\n",A[k]);
      }else
	  printf("%d ",A[k]);
	
      }
    }
    
    return 0;
  }
  

