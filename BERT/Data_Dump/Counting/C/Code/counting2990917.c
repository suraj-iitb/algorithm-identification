#include<stdio.h>
#include<stdlib.h>

#define max 10000

int main(){
  int *X, *Y;
  int Z[max+1];
  int n, i;

  scanf("%d", &n);
  X=malloc(sizeof(int)*n+1);
  Y=malloc(sizeof(int)*n+1);
  for(i=0 ; i<=max ; i++)Z[i]=0;
  for(i=0 ; i<n ; i++){
    scanf("%d", &X[i+1]);
    Z[X[i+1]]++;
  }
  for(i=1 ; i<=max ; i++)Z[i]=Z[i]+Z[i-1];
  for(i=0 ; i<=n ; i++){
    Y[Z[X[i]]]=X[i];
    Z[X[i]]--;
  }
  printf("%d",Y[1]);
  for(i=2 ; i<=n ; i++){
    printf(" %d",Y[i]);
  }
  printf("\n");
  return 0;
}
