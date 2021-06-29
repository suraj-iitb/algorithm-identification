#include <stdio.h>
#define A 100

int k=0;

void swap(int *x, int *y);
void selectionsort(int nums[], int array_size);

int main(void){
  int i,n;

  int list[A];

  scanf("%d",&n);

 for (i = 0; i < n; i++) { scanf("%d",&list[i]); }

  selectionsort(list, n);

  for(i = 0; i < n-1; i++){
    printf("%d ", list[i]);
  }
  printf("%d\n",list[i]);
  printf("%d",k);
  printf("\n");

  return 0;
}

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void selectionsort(int nums[], int array_size){
  int i, j;
  int min;

  for(i = 0; i < array_size; i++){
    min = i;

    for(j = i + 1; j < array_size; j++){

      if(nums[j] < nums[min])
        {
          min = j;
        }

        }
     swap(&nums[i], &nums[min]);
     if(min!=i){
         k++;
       }
      }
}

















