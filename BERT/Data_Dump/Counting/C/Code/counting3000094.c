#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define SMAX 10000

int main(){
  unsigned short *X,*Y;

  int D[SMAX+ 1];
  int num,j,i;
  scanf("%d",&num);

  X= malloc(sizeof(short) * num+1);
  Y = malloc(sizeof(short) * num +1);

  for(i=0;i<=SMAX;i++){
    D[i] = 0;
  }

  for(i=0;i<num; i++){
    scanf("%hu",&X[i+1]);
    D[X[i+1]]++;
    
  }

  for(i=1;i<=SMAX;i++){
    D[i]=D[i] + D[i-1];
}

  for(j=1;j<=num;j++){
    Y[D[X[j]]] = X[j];
    D[X[j]]--;
  }

  for(i=1;i<=num;i++){
    if(i>1){
      printf(" ");
    }
    printf("%d",Y[i]);
  }
  printf("\n");

  return 0;
}
  

