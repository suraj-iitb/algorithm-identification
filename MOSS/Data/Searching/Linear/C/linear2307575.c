#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, q, i, j, k = 0, key = 0;
  int *S, *T;

  scanf("%d", &n);
  S = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(q * sizeof(int));
  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);

  for(j = 0; j < q; j++){
    for(i = 0; i < n; i++){
      if(T[j] == S[i]){
	k++;
	break;
      }
    }
  }
  printf("%d\n", k);

  return 0;
}
