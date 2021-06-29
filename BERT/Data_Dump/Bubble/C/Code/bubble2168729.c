#include <stdio.h>

int main(void){

  int n, i, j, k, a[100], co = 0, c;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n-1; i++){
    for(j = 0; j < n-i-1; j++){
      if(a[j] > a[j+1]){
	k = a[j];
	a[j] = a[j+1];
	a[j+1] = k;
	co++;
      }
    }
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], co);

  return 0;
}
