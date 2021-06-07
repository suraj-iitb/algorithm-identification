#include <stdio.h>
int main(int argc, char const *argv[]) {

  int i,j;
  int count = 0;
  int num_S;
  int num_T;
  int start,end,middle;


  scanf("%d",&num_S);
  int S[num_S];
  for( i = 0 ; i < num_S ; i++ ){
    scanf("%d",&S[i]);
  }

  scanf("%d",&num_T);
  int T[num_T];
  for( i = 0 ; i < num_T ; i++ ){
    scanf("%d",&T[i]);
  }

  for( i = 0 ; i < num_T ; i++ ){

    start = 0;
    end = num_S;

    while( start < end ){

      middle = ( start + end ) / 2;

      if( S[middle] >T[i] ){
        end = middle;
      }else if( S[middle] < T[i] ){
        start = middle + 1;
      }else if( S[middle] == T[i] ){
        count++;
        break;
      }

    }

  }

  printf("%d\n",count);

  return 0;
}
