#include <stdio.h>
#define N 10000
#define Q 500

main(){
  int n, q, c, i, j;
  int s[N], t[Q];

  scanf("%d", &n);

  for( i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for( j = 0; j < q; j++){
  scanf("%d", &t[j]);
  }

  c = 0;
  for( i = 0; i < q; i++){
    for( j = 0; j < n; j++){
      if( s[j] == t[i] ){
	c++;
	break;
      }
    }
  }

  printf("%d\n", c);

  return 0;

}
