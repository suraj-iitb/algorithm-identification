#include <stdio.h>

#define N 100

void bubbleSort(int * ,int);

int main(){
  int array[N], n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &array[i]);

  bubbleSort(array, n);

  return 0;
}

void bubbleSort(int *array, int n){
  int flag = 1, i = 0, j, tmp, cnt = 0;

  while(flag){
    flag = 0;

    for(j = n - 1; j >= i + 1; j--){
      if(array[j] < array[j - 1]){
	tmp = array[j];
	array[j] = array[j - 1];
	array[j - 1] = tmp;

	flag = 1;
	cnt++;
      }
    }
    i++;
  }
  for(i = 0; i < n; i++){
    if(i == n - 1) printf("%d\n", array[i]);
    else printf("%d ", array[i]);
  }

  printf("%d\n", cnt);

}
