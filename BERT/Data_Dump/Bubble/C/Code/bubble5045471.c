#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a, b, i, n, flag = 1, count = 0;

  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  while(flag){
    flag = 0;
    for(i = n-1; i >= 1; i--){
      if(a[i] < a[i-1]){
	b = a[i];
	a[i] = a[i-1];
	a[i-1] = b;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1) printf(" ");
  }

  printf("\n%d\n", count);

  free(a);
  
  return 0;
}

