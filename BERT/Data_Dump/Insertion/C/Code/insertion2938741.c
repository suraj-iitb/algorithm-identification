#include <stdio.h>

int main(){
  
  int i,j,v,N,c;
  
  scanf("%d",&N);

  int A[N];
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(c=0;c<N;c++){
    printf("%d",A[c]);
    if(c<N-1){
      printf(" ");
    }
    else{
      printf("\n");
    }
  }
  
  
  for(i=1;i<=N-1;i++){
    
    v = A[i];
    j = i -1;
  

    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = v;
    
    for(c=0;c<N;c++){
      printf("%d",A[c]);
      if(c<N-1){
	printf(" ");
      }
      else{
	printf("\n");
      }
    }
  }
    return 0;
}

