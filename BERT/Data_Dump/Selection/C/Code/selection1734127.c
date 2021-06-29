#include <stdio.h>

#define N 100

int main()
{
  int i, j, mj, num, tmp, count=0;
  int array[N];

  scanf("%d", &num);

  for( i=0; i<num; i++){
    scanf("%d", &array[i]);
  }

  for( i=0; i<num; i++){
    mj = i;

    for( j=i; j<num; j++){
      if( array[j] < array[mj] )mj = j;
    }

    if( array[i] != array[mj]){
    tmp = array[i];
    array[i] = array[mj];
    array[mj] = tmp;
    count++;
    }
  }

  for( i=0; i<num-1; i++){
    printf("%d ", array[i]);
  }
  
  printf("%d\n%d\n", array[num-1], count);

  return 0;
}
