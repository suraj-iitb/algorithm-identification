#include <stdio.h>

int main(void){

  int n, a[100], i, j, minj, k, co = 0, coo;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n-1; i++){
    minj = i;
    coo = co;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]){
	if(co == coo) co++;
	minj = j;
      }
    }
    k = a[i];
    a[i] = a[minj];
    a[minj] = k;
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], co);

  return 0;
}
