#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  int num;
  int *line;
  int i,j;
  int temp;
  int count = 0;

  scanf("%d",&num);

  line = (int *)malloc( num * sizeof(int) );

  for( i = 0 ; i < num ; i++ )
    scanf("%d",&line[i]);

  for( i = 0 ; i < num-1 ; i++ ){
    for( j = num-1 ; j > i ; j-- ){
      if( line[j-1] > line[j] ){
        temp = line[j];
        line[j] = line[j-1];
        line[j-1] = temp;
        count++;
      }
    }
  }

  for( i = 0 ; i < num-1 ; i++ ){
    printf("%d ",line[i]);
  }

  printf("%d\n%d\n",line[num-1],count);

  return 0;
}
