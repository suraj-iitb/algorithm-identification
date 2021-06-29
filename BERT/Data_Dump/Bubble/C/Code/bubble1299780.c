#include <stdio.h>

int main(){
  int n, a[100], count = 0, x, i, j;

  scanf("%d" ,&n);
  for(i = 0; i < n; i++) scanf("%d" ,&a[i]);

  for(j = 0; j < n; j++){
    for(i = n - 1; i > 0; i--){
      if(a[i] < a[i - 1]){ 
	x = a[i];
	a[i] = a[i - 1];
	a[i - 1] = x;
	count++;
      }
    }
  }
  
  for(i = 0; i < n - 1; i++) printf("%d " ,a[i]);
  printf("%d\n%d\n" ,a[n - 1] ,count);

  return 0;
}
