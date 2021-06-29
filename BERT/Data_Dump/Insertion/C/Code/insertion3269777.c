#include <stdio.h>

int main(){

  int i,j,k,v;

  int N;
  
  scanf("%d",&N);

  int A[N];

  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }

  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1){
	printf(" ");
      }
    
  }
  printf("\n");

  for(i=1;i<N;i++){
  
    v=A[i];
    j=i-1;

    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
 
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k!=N-1){
	printf(" ");
      }
    }


      printf("\n");
    
  }


  return 0;
}
  

