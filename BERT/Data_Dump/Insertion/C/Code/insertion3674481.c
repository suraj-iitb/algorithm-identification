#include <stdio.h>

int
main(int argc, char *argv[])
{
  int n, a[100];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  for(int i = 0; i < n - 1; i++)
  {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);
  

  int key, j;
  for(int i = 1; i < n; i++)
  {
    key = a[i];
    j = i;
    while(j > 0 && a[j - 1] > key)
    {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = key;
    for(int k = 0; k < n - 1; k++)
    {
      printf("%d ", a[k]);
    }
    printf("%d\n", a[n - 1]);
  }

  return 0;

}
