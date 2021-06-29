#include <stdio.h>

#define BUF_SIZE 1000
#define ARR_SIZE 100

void print_array(int array[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    if(i > 0) printf(" ");
    printf("%d", array[i]);
  }

  printf("\n");

  return ;
}

int bubble_sort(int array[], int size)
{
  int flag = 1;
  int tmp, j;
  int swap_size;
  int count = 0;

  while(flag){
    flag = 0;
    for(j = size - 1; 0 < j; j--){
      if(array[j] < array[j-1]){
        tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
  }

  return count;
}

int main(void)
{
  char buf[BUF_SIZE];
  int array[ARR_SIZE];
  int size, i, swap_size;

  fgets(buf, BUF_SIZE, stdin);
  sscanf(buf, "%d", &size);

  for(i = 0; i < size; i++){
    scanf("%d", &array[i]);
  }

  swap_size = bubble_sort(array, size);

  print_array(array, size);
  printf("%d\n", swap_size);

  return 0;
}
