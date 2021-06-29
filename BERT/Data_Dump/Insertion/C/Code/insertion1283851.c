#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[100];
  int n, v, i, j, k;

  /*n,aの要素の入力*/
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(i = 0; i < n - 1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[n - 1]);

  /*ソートの処理、出力*/
  for(i = 1; i <= n - 1; i++)
    {
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v)
      {
      a[j + 1] = a[j];
      j--;
      a[j + 1] = v;
      }
    for(k = 0; k < n - 1; k++)
      printf("%d ", a[k]);
    printf("%d\n", a[n - 1]);
    }
  return 0;
}
