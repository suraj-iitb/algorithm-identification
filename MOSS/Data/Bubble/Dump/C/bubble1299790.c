#include <stdio.h>

int main() {
  int n, i, j, array[100], count = 0, x;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &array[i]);

  for(i = 0; i < n; i++){
    for(j = (n-1); j >= i; j--){
      if(array[j] < array[j-1]){
        x = array[j];
        array[j] = array[j-1];
        array[j-1] = x;
        count++;
      }
    }
  }

    for(i =0; i < (n-1); i++)
      printf("%d ", array[i]);

    printf("%d\n", array[n-1]);
    printf("%d\n", count);

    return 0;
}
