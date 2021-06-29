#include <stdio.h>
#define N 100

int main(){
  int i, j, tmp, num, count = 0, array[N];

  //input data number and actual data
  scanf("%d", &num);
  for (i = 0; i < num; i++)
    scanf("%d", &array[i]);

  //bubble sorting procedure
  for (i = 0; i < num; i++){
    for (j = num-1; j >=i+1; j--){//traverses sub-array
      if (array[j-1] > array[j]){//exhange procedure
	tmp = array[j];
	array[j] = array[j-1];
	array[j-1] = tmp;
	count++;
      }
    }
  }

  //display procedure
  for (i = 0; i < num; i++){
    printf("%d", array[i]);
    if (i < num -1)
      printf(" ");
  }
  
  printf("\n%d\n", count);

  return 0;
}

