#include <stdio.h>

int main(){

  int array[100];
  int i, j, k, v;
  int n;

  scanf("%d", &n);
  if(n < 1 || n > 100)
    return 0;

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
    if(array[i] < 0 || array[i] > 1000)
      return 0;
  }


  for(i = 0; i < n-1; i++)
    printf("%d ", array[i]);
  printf("%d\n", array[n-1]);


  for(i = 1; i < n-1; i++){
    v = array[i];
    j = i-1;
    while(j >= 0 && array[j] > v){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = v;


    for(k = 0; k < n-1; k++)
      printf("%d ", array[k]);
    printf("%d\n", array[n-1]);

  }

  v = array[n-1];
  j = n-2;
  while(j >= 0 && array[j] > v){
    array[j+1] = array[j];
    j--;
  }
  array[j+1] = v;

  if(n > 2){
    for(i = 0; i < n-1; i++)
      printf("%d ", array[i]);
    printf("%d\n", array[n-1]);
  }

  return 0;

}
