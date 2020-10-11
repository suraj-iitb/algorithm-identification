#include<stdio.h>
#include<stdlib.h>

int flag = 0;
int a[100001];
char c[100001][2];
int ma[100001];
char mc[100001];

void quickSort(int, int);
int partition(int, int);
void swap(int ,int);

void mergeSort(int, int);
void merge(int, int, int);

int main()
{
  int n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    {
      scanf("%s %d", &c[i][0], &a[i]);
      mc[i] = c[i][0];
      ma[i] = a[i];
    }

  quickSort(0, n-1);
  mergeSort(0, n);

  for(i = 0; i < n; i++)
    {
      if(c[i][0] != mc[i])flag = 1;
    }

  if(flag)printf("Not stable\n");
  else printf("Stable\n");
  
  for(i = 0; i < n; i++)
    {
      printf("%c %d\n", c[i][0], a[i]);
    }
  return 0;
}

int partition(int l, int r)
{
  int temp, i, j;

  temp = a[r];
  i = l;
  
  for(j = l; j <= r; j++)
    {
      if(a[j] <= temp)
	{
	  swap(i, j);
	  i++;
	}
    }

  return i-1;
}

void swap(int i, int j)
{
  int t;
  char temp;

  if(i == j)return;

  t = a[i];
  a[i] = a[j];
  a[j] = t;
  
  temp = c[i][0];
  c[i][0] = c[j][0];
  c[j][0] = temp;
}

void quickSort(int l, int r)
{
  int p;
  
  if(l < r)
    {
      p = partition(l, r);
      quickSort(l, p-1);
      quickSort(p+1, r);
    }

  return;
}

void merge(int left,int mid, int right)
{
  int *l, *r;
  char *lc, *rc;
  int n1, n2, i, j, k;
  int inf=1000000000;
  n1 = mid-left;
  n2 = right-mid;

  l = malloc(sizeof(int)*(n1+1));
  lc = malloc(sizeof(char)*(n1+1));
  r = malloc(sizeof(int)*(n2+1));
  rc = malloc(sizeof(char)*(n2+1));

  for(i = 0; i < n1; i++)
    {
      l[i] = ma[left+i];
      lc[i] = mc[left+i];
    }
  l[n1] = inf;
  for( i = 0; i < n2; i++)
    {
      r[i] = ma[mid+i];
      rc[i] = mc[mid+i];
    }
  r[n2] = inf;

  i = 0;
  j = 0;
  
  for(k = left; k < right;k++)
    {
      if(l[i] <= r[j])
	{
	  ma[k] = l[i];
	  mc[k] = lc[i];
	  i++;
	}
      else
	{
	  ma[k] = r[j];
	  mc[k] = rc[j];
	  j++;
	}
    }
  return;
}

void mergeSort(int left, int right)
{
  int mid;

   if(left+1 < right)
    {
      mid = (right+left) / 2;
      mergeSort(left, mid);
      mergeSort(mid, right);
      merge(left,mid,right);
    }
   return;
}



