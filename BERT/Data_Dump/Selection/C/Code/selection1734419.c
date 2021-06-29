#include <stdio.h>

#define N 100

void selectionSort(int *, int);

int main(){
  int array[N], n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &array[i]);

  selectionSort(array, n);

  return 0;
}

void selectionSort(int *array, int n){
  int i, j, tmp, min, cnt=0;

  for(i = 0; i <= n - 1; i++){
    min = i;
    for(j = i; j <= n - 1; j++)
      if(array[j] < array[min]) min = j;
    if(i != min){
      tmp = array[i];
      array[i] = array[min];
      array[min] = tmp;
      cnt++;
    }
  }

  for(i = 0; i < n; i++){
    if(i == n - 1) printf("%d\n", array[i]);
    else printf("%d ",array[i]);
  }

  printf("%d\n", cnt);

}
