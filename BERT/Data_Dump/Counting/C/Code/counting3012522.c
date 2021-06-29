#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000
main(){
  unsigned short *D, *E;
  int T[VMAX+1];
  int n, i, j;
  scanf("%d", &n);
  D = malloc(sizeof(short)*n+1);
  E = malloc(sizeof(short)*n+1);
  for ( i=0;i<=VMAX;i++) T[i]=0;
  for ( i=0;i<n;i++){
    scanf("%d", &D[i+1]);
    T[D[i+1]]++;
  }
  for ( i=1; i<= VMAX; i++ ) T[i] = T[i] + T[i-1];
  for ( j=1; j <= n;j++ ){
    E[T[D[j]]] = D[j];
    T[D[j]]--;
  }
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", E[i]);
  }
  printf("\n");
  return 0;
}

