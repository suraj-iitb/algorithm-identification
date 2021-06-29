#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  int num;
  int *line;
  int i,j,minj;
  int temp,count=0;

  scanf("%d",&num);

  line = (int *)malloc( num * sizeof(int) );

  for( i = 0 ; i < num ; i++ ){
    scanf("%d",&line[i]);
  }

  for( i = 0 ; i < num ; i++ ){

    minj = i;

    for( j = i ; j < num ; j++ ){

      if( line[j] < line[minj] ){
        minj = j;
      }

    }

    if( i != minj ){

    temp = line[i];
    line[i] = line[minj];
    line[minj] = temp;
    count++;

    }

  }



  for( i = 0 ; i < num-1 ; i++ )
    printf("%d ",line[i]);

  printf("%d\n%d\n",line[num-1],count);

  free(line);

  return 0;
}
