#include<stdio.h>
#include<limits.h>

int a[500002];
int l[250001];
int r[250001];
int cnt = 0;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main()
{
  int n;
  int i;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
    scanf("%d",&a[i]);
  }

  mergeSort(a,0,n);

  for(i = 0; i < n-1;i++)
  {
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",cnt);
  return 0;
}

void merge(int *a,int left,int mid,int right)
{
  int n1, n2;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i < n1;i++)
  {
    l[i] = a[left + i];
  }
  for(i = 0;i < n2;i++)
  {
    r[i] = a[mid + i];
  }
  l[n1] = INT_MAX;
  r[n2] = INT_MAX;
  i = 0;
  j = 0;
  for(k = left;k < right;k++)
  {
    if(l[i] <= r[j])
    {
      a[k] = l[i];
      i++;
    }
    else
    {
      a[k] = r[j];
      j++;
    }
    cnt++;
  }
}

void mergeSort(int *a,int left,int right)
{
  int mid;
  if(left+1 < right)
  {
    mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

