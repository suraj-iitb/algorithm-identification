#include <stdio.h>

#define N 100

int main()
{
  int num, i, j, tmp, flag, count=0;
  int array[N];

  scanf("%d", &num);

  for( i=0; i<num; i++){
    scanf("%d", &array[i]);
  }

  for( i=0; i<num; i++){
    flag = 1;

    while( flag ){
      flag = 0;

      for( j=num-1; j>0; j--){
	if( array[j] < array[j-1] ){
	  tmp = array[j];
	  array[j] = array[j-1];
	  array[j-1] = tmp;
	  flag = 1;
	  count++;
	  break;
	}
      }
    }
  }

  for( i=0; i<num-1; i++){
    printf("%d ", array[i]);
  }

  printf("%d\n%d\n", array[num-1], count);

  return 0;
}
