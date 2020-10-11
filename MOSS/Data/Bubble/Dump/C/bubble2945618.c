#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *numbers, int array_size)
{
  int i, j, temp,count=0;

  for (i = 0; i < (array_size - 1); i++) {
    for (j = (array_size - 1); j > i; j--) {

      if (numbers[j-1] > numbers[j]) {
	count++;
	temp = numbers[j-1];
	numbers[j-1] = numbers[j];
	numbers[j] = temp;
      }
    }
  }
  return count;
}

int main(){
  int array_size,i,count;
  int *numbers;

  scanf("%d",&array_size);

  numbers = (int *)malloc(sizeof(int) * array_size);

  for(i = 0;i<array_size;i++){
    scanf("%d",&numbers[i]);
  }

  count = bubbleSort(numbers,array_size);

  for(i = 0;i<array_size;i++){
    if(i == array_size - 1)
      printf("%d\n",numbers[i]);
    else
      printf("%d ",numbers[i]);
  }

  printf("%d\n",count);

  return 0;

}

