#include <stdio.h>

#define S_SIZE 10000
#define T_SIZE 500
int main(void)
{
  long S[S_SIZE];
  int n;
  int i;
  long T[T_SIZE];
  int q;
  int found = 0;

  scanf("%5d", &n);
  for(i=0; i < n; i++) scanf("%10ld", &S[i]);

  scanf("%3d", &q);
  for(i=0; i < q; i++) scanf("%10ld", &T[i]);

  for(i=0; i < q; i++){
    int f, j;
    f = T[i];

    for(j = 0; j < n; j++){
      if(f == S[j]) break;
    }
    if(j < n) found++;
  }

  printf("%d\n", found);

  return 0;
}
