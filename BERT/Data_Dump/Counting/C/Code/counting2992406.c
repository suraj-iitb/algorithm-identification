/*計数ソート*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *a, *b;
  int c[VMAX+1];
  int n, i, j, k;
  
  scanf("%d", &n);
  
  a = malloc(sizeof(int)*n+sizeof(int));
  b = malloc(sizeof(int)*n+sizeof(int));

  scanf("%d", &a[0]);
  k = a[0];
  for (i=1; i<n; i++){
    scanf("%d", &a[i]);
    if (a[i]>k)
      k = a[i];
  }
  
  for (i=0; i<=k; i++){
    c[i] = 0;
  }
  
  for (j=0; j<n; j++){
    c[a[j]]++;
  }

  for (i=1; i<=k; i++){
    c[i] += c[i-1];
  }
  
  for (j=n-1; j>=0; j--){
    b[c[a[j]]-1] = a[j];
    c[a[j]]--;
  }

  
  for (i=0; i<n-1; i++){
    printf("%d ", b[i]);
  }
  printf("%d\n", b[n-1]); 
  
  return 0;
}

