#include <stdio.h>

int main(void)
{
 int n, q, i, j, l;
 int a[10000];
 int b[500];
 int c[500];
 int k = 0;
 int v = 0;
 
 scanf("%d", &n);
 
 for(i = 0; i < n; i++)
  scanf("%d", &a[i]);

 scanf("%d", &q);

 
 for(i = 0; i < q; i++)
  scanf("%d", &b[i]);

 for(j = 0; j < n; j++)
 {
  for(i = 0; i < q; i++)
 {
  if(a[j] == b[i])
{ 
  c[v] = b[i];
  v++;
  k++;
}
 
 }

 }

 for(j = 0; j < v; j++)
{
 for(i = j+1; i < v; i++)
{
 if(c[j] == c[i])
{
  k--;
  break;
}
 }
}

 
 printf("%d\n", k);


 return 0;

}


 
 
