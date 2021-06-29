#include<stdio.h>

int a[2000001],b[2000001];
void CountingSort(int *,int *,int,int);

int main()
{
  int n,i;

  scanf("%d",&n);
  for(i = 1;i <= n;i++)
  {
    scanf("%d",&a[i]);
  }
  CountingSort(a,b,10000,n);

  for(i = 1; i < n;i++)
  {
    printf("%d ",b[i]);
  }
  printf("%d\n",b[n]);
  return 0;
}

void CountingSort(int *a,int *b,int k,int n)
{
  int c[10001];
  int i,j;
  for(i = 0;i <= k; i++)
  {
    c[i] = 0;
  }

  for(j = 1;j <= n;j++)
  {
    c[a[j]]++;
  }

  for(i = 1;i <= k;i++)
  {
    c[i] = c[i] + c[i-1];
  }
  for(j = n;j > 0;j--)
  {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}

