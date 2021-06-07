#include <stdio.h>

#define N 10000
#define Q 500

int main(){

  int i, j;
  int s[N], t[Q];
  int n, q;
  int count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);

  }

 scanf("%d", &q);

  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);

  }

  /*for(i = 0; i < n; i++){//S
    for(j = 0; j < q; j++){//T

      if(s[i] == t[j]){
	count++;
	break;
      }

    }
    }*/

  for(i = 0; i < q; i++){//T
    for(j = 0; j < n; j++){//S

      if(t[i] == s[j]){
	count++;
	break;
      }

    }
  }

  printf("%d\n", count);

  return 0;
}
