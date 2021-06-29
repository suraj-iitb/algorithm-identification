#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  int num;
  int *line;
  int i,j,k;
  int key;

  scanf("%d",&num);
  line = (int *)malloc(num * sizeof(int));

  for( i = 0 ; i < num ; i++ ){
    scanf("%d",&line[i]);
  }

  for( i = 1 ; i < num ; i++ ){

    key = line[i];
    j = i - 1;

    for( k = 0 ; k < num ; k++ ){
      printf("%d",line[k]);
      if ( k != num-1 )
        printf(" ");
    }
    printf("\n");

    while( line[j] > key ){


      line[j+1] = line[j];
      j--;

    }

    line[j+1] = key;

  }

  for( k = 0 ; k < num ; k++ ){
    printf("%d",line[k]);
    if( k != num-1 )
      printf(" ");
  }
  printf("\n");

  free(line);


  return 0;
}
