#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10001

int main(){
  unsigned short *N, *M;

  int L[VMAX];
  int n, i, j;
  
  scanf("%d", &n);

  N = malloc(sizeof(short)*n+1);
  M = malloc(sizeof(short)*n+1);

  for ( i = 0; i <= VMAX-1; i++ ) L[i] = 0;
  for ( i = 0; i < n; i++ ){
    scanf("%d", &N[i+1]);
    L[N[i+1]]++;
  }
  
  for ( i = 1; i <= VMAX-1; i++ ) L[i] = L[i] + L[i-1];
  for ( j = 1; j <= n; j++ ){
    M[L[N[j]]] = N[j];
    L[N[j]]--;
  }
  
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", M[i]);
  }
  printf("\n");
  return 0;
}

