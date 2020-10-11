#include <stdio.h>
#include <stdlib.h>

int SelectionSort(int *a, int n);

int main(void){
  int i, n, *a, ans;

  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if(a == NULL){
    printf("?????¢????¢??????¨??????\n");
    return -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  ans = SelectionSort(a, n);
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n%d\n", ans);
  free(a);
  return 0;
}


int SelectionSort(int *a, int n){
  int min, i, j, temp, count = 0;

  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++){
      if(a[min] > a[j]){
	min = j;
      }
    }
    if(min != i){
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
      count++;
    }
  }
  return count;
}
