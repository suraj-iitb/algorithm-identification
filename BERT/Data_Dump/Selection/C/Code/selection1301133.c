#include <stdio.h>

int main() {

  int i, j, k, min, n, x, array[100], count=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &array[i]);

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(array[j] < array[min])
        min = j;
    }

    if(i != min){
      x = array[i];
      array[i] = array[min];
      array[min] = x;
      count++;
    }

  }

  for(i = 0; i < n-1; i++)
    printf("%d ", array[i]);

  printf("%d\n", array[n-1]);
  printf("%d\n", count);

  return 0;
}
