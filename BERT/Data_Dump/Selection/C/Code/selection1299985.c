#include <stdio.h>

int main(){
  int n, a[100], min_a, min, count = 0, x, i, j;

  scanf("%d" ,&n);
  for(i = 0; i < n; i++) scanf("%d" ,&a[i]);

  for(i = 0; i < n; i++){
    min_a = a[i];
    min = i;
    for(j = i; j < n; j++){
      if(min_a > a[j]){
	min_a = a[j];
	min = j;
      }
    }
    if(i != min){
    x = a[min];
    a[min] = a[i];
    a[i] = x;
    count++;
    }
  }
  for(i = 0; i < n - 1; i++) printf("%d " ,a[i]);
  printf("%d\n%d\n" ,a[n - 1] ,count);
  return 0;
}
