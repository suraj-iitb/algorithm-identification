#include<stdio.h>
#include<stdlib.h>


int main(){

  int i=0,j,m,k,a;
  int *n;
  int count = 0;

  scanf("%d",&k);

  n = malloc(sizeof(int) * k);
  
  while(i < k){
    scanf("%d",&n[i]);
    i++;
    }

  m = 0;
  while(m != k-1){

  for(i=k-1; i > 0 ; i--){

    
    if(n[i] < n[i-1]){

      a = n[i-1];

      n[i-1] = n[i];

      n[i] = a;

      count++;
    }
    else if(n[i] > n[i-1]){
      continue;
    }
    
  }
  m++;
  }

  i = 0;

  while(i < k){
    printf("%d",n[i]);
    if(i != k-1){
      printf(" ");
      
    }

    i++;

  }
    printf("\n");

  printf("%d\n",count);

  free(n);


  return 0;
}
