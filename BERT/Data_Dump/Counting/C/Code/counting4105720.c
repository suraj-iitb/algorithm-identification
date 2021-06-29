#include<stdio.h>
#include <stdlib.h>

#define N 10000

int main(){
  int i,j,n,a,c,k,C[N+1];
  unsigned long *in,*result;

  
  for(i=0;i<=N;i++){
    C[i]=0;
  }
  
  scanf("%d",&n);

  in = malloc(sizeof(long)*n+1);
  result = malloc(sizeof(long)*n+1);
  
  for(i=0;i<n;i++){
    scanf("%d",&in[i+1]);
    C[in[i+1]]++;
  }

  for(i=1;i<=N;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=1;j<=n;j++){
    result[C[in[j]]] = in[j];
    C[in[j]]--;
  }
  
  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",result[i]);
  }
  
  printf("\n");
  return 0;
}

