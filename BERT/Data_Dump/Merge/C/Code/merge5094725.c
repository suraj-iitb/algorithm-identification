#include <stdio.h>
#include <limits.h>

#define N 500000

int count=0,n;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main()
{
  int s[N],i,left=0;

  scanf("%d",&n);
  for(i=0 ; i < n ; i++)
    scanf("%d",&s[i]);
  mergeSort(s,left,n);

  for(i=0 ; i < n-1 ; i++)
    printf("%d ",s[i]);
  printf("%d\n",s[n-1]);
  printf("%d\n",count);

  return 0;
}
void merge(int *s,int left,int mid,int right)
{
  int i,j=0,k,l[mid - left + 1],r[right - mid + 1],n1,n2;

  n1 = mid - left;
  n2 = right - mid;
  for(i = 0 ; i < n1 ; i++)
    l[i] = s[left + i];
  for(i = 0 ; i < n2 ; i++)
    r[i] = s[mid + i];
  l[n1] = r[n2] = INT_MAX;
  i = 0;
  for(k = left ; k < right ; k++)
    {
      count++;
      if(l[i] <= r[j])
        {
          s[k] = l[i];
          i++;
        }
      else
        {
          s[k] = r[j];
          j++;
        }
    }
}
void mergeSort(int *s,int left,int right)
{
  int mid,i;

  if(left+1 < right)
    {
      mid = (left + right)/2;
      mergeSort(s, left, mid);
      mergeSort(s, mid, right);
      merge(s, left, mid, right);
    }
}
