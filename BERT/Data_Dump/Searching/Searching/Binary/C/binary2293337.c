#include <stdio.h>
#include <stdlib.h>

int binarySearch(int key);

int *S, n, k = 0;

int main()
{
  int *T;
  int q, i, tmp;

  scanf("%d", &n);
  S = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(q * sizeof(int));
  for(i = 0; i < q; i++)
    scanf("%d", &T[i]);

  /* printf??§??????????¢????
     for(i = 0; i < n; i++)
     printf("%d ", S[i]);
     printf("\n");

     for(i = 0; i < q; i++)
     printf("%d ", T[i]);
     printf("\n");
  */

  for(i = 0; i < q; i++){
    tmp = binarySearch(T[i]);
    //  printf("tmp = %d\n", tmp);
    //if(tmp == 0)
    //  fprintf(stderr, "NOT_FOUND\n");
    }

  printf("%d\n", k);
  return 0;
}


int binarySearch(int key)
{
  int left = 0, right = n, mid;

  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      k++;
      return mid;
    }
    else if(key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return 0;
}
