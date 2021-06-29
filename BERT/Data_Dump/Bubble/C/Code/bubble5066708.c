#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, x[100], temp, change = 0;
  int i, j;

  scanf("%d", &n);
  if(n < 0 || n > 100){
    exit(1);
  }

  for(i = 0; i < n; i++){
    scanf("%d", &x[i]);
  }

  i = 0;

  while(i < n){
    for(j = n-1; j > i; j--){
      if(x[j] < x[j-1]){
        temp = x[j-1];
        x[j-1] = x[j];
        x[j] = temp;
        change++;
      }
    }
    i++;
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", x[i]);
  }
  printf("%d\n%d\n", x[n-1], change);
  
  return 0;
}
