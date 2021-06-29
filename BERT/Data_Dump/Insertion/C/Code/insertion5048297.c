#include<stdio.h>

#define N 100


int main(){
  int A[N], i, j, k,l, a;
  
  
  scanf("%d",&i);
  
  for(j = 0 ; j < i ; j++){
    scanf("%d",&A[j]);
  }

  for(l = 0 ; l < i ; l++){
if(l != 0)printf(" ");
    printf("%d",A[l]);
  }
  printf("\n");
  
  
  for(j = 1 ; j < i ; j++){
    a = A[j];
    k = j - 1;
    while( k >= 0 && A[k] > a){
      A[k+1] = A[k];
      k--;
    }
    A[k+1] = a;
    
    for(l = 0 ; l < i ; l++){
	if(l != 0)printf(" ");
      printf("%d",A[l]);
    }
	printf("\n");
  }
  return 0;
}
	

	   

