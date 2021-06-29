#include <stdio.h>
#define N 100

int main(){
  int i, j, num, array[N], count = 0, mini_j, tmp;

  //input data number and actual data
  scanf("%d", &num);
  for (i = 0; i < num; i++)
    scanf("%d", &array[i]);

  //selection sort procedure
  for (i = 0; i < num; i++){
    mini_j = i;
    //find smallest value
    for (j = i; j < num; j++)
      if (array[j] < array[mini_j])
	mini_j = j;
    //exhange procedure
    if (mini_j != i){
      count++;
      tmp = array[i];
      array[i] = array[mini_j];
      array[mini_j] = tmp;
    }
  }

  //display procedure
  for (i = 0; i < num; i++){
    printf("%d", array[i]);
    if (i < num-1)
      printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}
  

