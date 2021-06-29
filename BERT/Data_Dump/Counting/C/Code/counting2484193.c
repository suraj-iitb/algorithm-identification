#include <stdio.h>
 
#define N 10010
  
int C[N] = {0};
  
int main()
{
  int i, j;
  int n;
  int a;
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &a);
    C[a]++;
  }
      
  int l = 0;
  for (i = 0; i < N; i++){
    if (C[i] != 0) l = i;
  }
      
  for (i = 0; i < l; i++){
    for (j=0; j<C[i]; j++){
      printf("%d ", i);
    }
  }
 
  for (i = 0; i < C[l] - 1; i++)
    printf("%d ", l);
  
  printf("%d\n", l);
      
  return 0;
}
