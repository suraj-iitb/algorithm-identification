#include <stdio.h>
#include <stdlib.h>

main(){
  int i, n, *a,c[10001], *b, j;

  scanf("%d", &n);

  a = malloc(sizeof(int)*n+1);
  b = malloc(sizeof(int)*n+1);

  for(j = 0;j < 10001;j++) c[j] = 0;

  for(i = 0;i < n;i++){ 
    scanf("%d", &a[i+1]);
    c[a[i+1]]++;
  }
  
  for(j = 1;j <= 10001;j++) c[j] = c[j] + c[j - 1];
  
  for(j = 1;j <= n;j++){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
  
  for(i = 1;i < n;i++)  printf("%d ", b[i]);
  printf("%d\n", b[i]);
  return 0;
}
