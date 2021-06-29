#include <stdio.h>
#define N 10000

int main()
{
  int num,q,t,i;
  int S[N],count;

  scanf("%d", &num);
  for(i = 0; i < num; ++i) {
    scanf("%d", &S[i]);
  }

  count = 0;

  scanf("%d", &q);
  while(q--){
    scanf("%d", &t);
    for(i = 0; i < num; ++i) {
      if(S[i] == t) {
        ++count;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
