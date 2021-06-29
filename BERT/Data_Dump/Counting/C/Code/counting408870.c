#include<stdio.h>
#define N 2000010

void countingSort(int, int);
static int a[N], b[N], c[N];

int main()
{
  int n;
  int i, j, k;

  scanf("%d", &n);
  j=0;
  for(i=1; i<=n; i++)
    {
      scanf("%d", &a[i]);
      if(j<a[i])j=a[i];
    }

  //sort
  countingSort(j, n);

  //print
  for(i=1; i<n; i++)printf("%d ", b[i]);
  printf("%d\n", b[n]);
  return 0;
}

//sort
void countingSort(int max, int n)
{
  int i, j, k;

  for(i=0; i<=max; i++)c[i]=0;
  for(i=1; i<=n; i++)c[a[i]]++;

  for(i=1; i<=max; i++)
    {
      if(i!=0)c[i]+=c[i-1];
    }

  for(i=n; i>=1; i--)
    {
      b[c[a[i]]]=a[i];
      c[a[i]]--;
    }
}
