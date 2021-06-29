#include <stdio.h>
#include <stdlib.h>

#define N 100
#define A 100

int main(){
  int i, j, n, a[A], minimum, temp1, temp2, count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < n; i++){
    minimum = i;
    for(j = i; j < n; j++){

      if(a[j] < a[minimum]){
	minimum = j;
      }
    }
    if(minimum != i){
      temp1 = a[minimum];
      temp2 = a[i];
      a[minimum] = temp2;
      a[i] = temp1;
      count++;
    }
  }

  for(i = 0; i < n; i++){
    if(i == n - 1){
      printf("%d", a[i]);
      continue;
    }

    printf("%d ", a[i]);
  }

  printf("\n%d\n", count);

  return 0;
}

