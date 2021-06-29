#include <stdio.h>
#include <stdlib.h>
int main(){

  int i, j, k, size, tmp;

  scanf("%d", &size);

  int arr[size];

  for(i = 0; i < size; i++)
    scanf("%d", &arr[i]);


  for(i = 1; i <= size-1; i++){

    //show arr during sorting.
    for(k = 0; k < size-1; k++)
      printf("%d ", arr[k]);
    printf("%d", arr[k]);
    printf("\n");

    tmp = arr[i];

    //insert arr[i] into the sorted sequence arr[0, ... , j-1]
    j = i - 1;
    while(j >= 0 && arr[j] > tmp){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = tmp;

  }

  for(i = 0; i < size-1; i++)
    printf("%d ", arr[i]);
  printf("%d", arr[k]);
  printf("\n");

  return 0;
}
