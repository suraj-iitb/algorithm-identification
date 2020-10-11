#include <stdio.h>

#define BUF_SIZE 1000
#define ARR_SIZE 100

void print_arr(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  printf("\n");
  return ;
}

int selection_sort(int arr[], int size)
{
  int i, j;
  int count= 0;
  int flag = 0;

  for(i = 0; i < size; i++){
    int minj;
    minj = i;
    for(j = i; j < size; j++){
      if(arr[j] < arr[minj]){
        minj = j;
        flag = 1;
      }
    }

    int tmp;
    tmp = arr[i];
    arr[i] = arr[minj];
    arr[minj] = tmp;

    if(flag) count++;
    flag = 0;
  }

  return count;
}
int main(void)
{
  char buf[BUF_SIZE];
  int arr[ARR_SIZE];
  int size, i;
  int count;

  fgets(buf, BUF_SIZE, stdin);
  sscanf(buf, "%d", &size);

  for(i=0; i < size; i++) scanf("%d", &arr[i]);

  count = selection_sort(arr, size);

  print_arr(arr, size);
  printf("%d\n", count);

  return 0;
}
