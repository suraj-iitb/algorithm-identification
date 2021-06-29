#include <stdio.h>

void swap(int *a, int *b);

int main(){
  int n, list[100], i, j, count = 0, temp;

  scanf("%d", &n);

  for(i = 0; i < n; i++) scanf("%d", &list[i]);

  for(i = 0; i < n-1; i++)
    for(j = n-1; j > i; j--)
      if(list[j] < list[j-1]){
	swap(&list[j], &list[j-1]);
	count++;
      }

  for(i = 0; i < n-1; i++) printf("%d ", list[i]);
  printf("%d\n%d\n", list[i], count);
  
  return 0;
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
