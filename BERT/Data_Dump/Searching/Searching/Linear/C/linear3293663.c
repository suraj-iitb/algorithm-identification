#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, q, i, count = 0, k; 
  int *S, *T;

  scanf("%d", &n);
  S = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(n * sizeof(int));
  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);


  /*確認のprintf*/
  /*
    printf("n = %d\n", n);
    for(i = 0; i < n; i++)
    printf("%d ", S[i]);
   
    printf("\n");
    printf("q = %d\n", q);
    for(i = 0; i < q; i++)
    printf("%d ", T[i]);
   
    printf("\n");
  */

  for(k = 0; k < q; k++){
    for(i = 0; i < n; i++){
      if(T[k] == S[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n", count);

  return 0;
}

