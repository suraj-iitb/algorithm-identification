#include<stdio.h>
#define K 2000001

int a[K];
int b[K];
int c[K];

int main()
{
  int i,j;
  int n;
  

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&a[i]);

  for(i = 0; i < K; i++)c[i] = 0;


  for(i = 0; i < n; i++) c[a[i]]++;
   

  for(i = 1; i < K; i++) c[i] += c[i-1];

  for(i = n-1; i >= 0; i--)
    {
      b[c[a[i]]] = a[i];
      c[a[i]]--;
    }
  for(i = 1; i < n+1; i++)
    {
      printf("%d",b[i]);
      if(i == n)printf("\n");
      else printf(" ");
    }

  
  return 0;
}
  

