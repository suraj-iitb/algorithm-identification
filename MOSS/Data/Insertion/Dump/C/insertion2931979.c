#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,z,N;
  int v;
  int *A; 
  scanf("%d",&N);
 
  A = malloc(N * sizeof(int)); 

  for(i=0;i<N;i++){
  scanf("%d",&A[i]);
  }
 for(z=0;z<N;z++){
      printf("%d",A[z]);
      if(z != N -1){
	printf(" ");
      }
    }
    printf("\n");
  
  for(i=1;i<N;i++){
    v = A[i];
    j = i - 1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
      
      
    }
    for(z=0;z<N;z++){
      printf("%d",A[z]);
      if(z != N -1){
	printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}

