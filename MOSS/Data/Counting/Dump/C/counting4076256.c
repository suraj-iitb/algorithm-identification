#include<stdio.h>
#include<stdlib.h>
#define M 10000

int main(){
  
  unsigned short *X, *Y;

  int Z[M+ 1];
  
  int a,i,j;
  
  scanf("%d",&a);

  X = malloc(sizeof(short)*a + 1);
  Y = malloc(sizeof(short)*a + 1);

  for(i = 0; i <= M; i++){
    Z[i] = 0;
  }

  for(i = 0; i < a; i++){
    scanf("%hd",&X[i + 1]);
    Z[X[i + 1]]++;
    
  }
  for(i = 1; i <= M; i++){
    
    Z[i] = Z[i] + Z[i - 1];
    
  }
  for(j = 1; j <= a; j++){
    
    Y[Z[X[j]]] = X[j];
    
    Z[X[j]]--;
    
  }

  for(i = 1; i <= a; i++){
    
    if(i > 1){
      printf(" ");
    }
    
    printf("%d",Y[i]);
    
  }
  
  printf("\n");

  return 0;
}


