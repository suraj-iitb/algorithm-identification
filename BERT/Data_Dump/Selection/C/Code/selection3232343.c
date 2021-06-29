#include <stdio.h>

int main(void)

{
 int i, j, minj, n, s;
 int a[100];
 int c = 0;

 scanf("%d", &n);

 for(i = 0; i < n; i++)
 scanf("%d", &a[i]);

 for(i = 0; i < n; i++)
{
 minj = i;

 for(j = i; j < n; j++)
  if(a[minj] > a[j])
    minj = j;

 s = a[i];
 a[i] = a[minj];
 a[minj] = s;
 
 if(i != minj)
  c++;

 }

 for(i = 0; i < n; i++)
  if(i < n-1)
    printf("%d ", a[i]);
  else
    printf("%d", a[i]);

 printf("\n%d\n", c);

 return 0;

}

