#include <stdio.h>
int main(int argc, char const *argv[]) {

  int i,j;
  int count = 0;
  int num_S;
  int num_T;

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

    for( j = 0 ; j < num_S ; j++ ){

      if( T[i] == S[j] ){
        count++;
        break;
      }

    }


  }

  printf("%d\n",count);

  return 0;
}
