#include <stdio.h>

int main(){

  int i, j, n, q, output;
  int S[10000], T[500];
  output = 0;

  scanf("%d", &n);
  for( i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for( i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for( i = 0; i < q; i++){
    for( j = 0; j < n; j++){
      if( S[j] == T[i] ){
        output++;
        j = j + n;
      }
    }
  }

  printf("%d\n", output);

  return 0;
}
