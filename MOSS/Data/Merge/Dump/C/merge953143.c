#include<stdio.h>
#define LEN 500000

void merge(int [], int, int, int);
void merge_sort(int [], int, int);

int n, S[LEN];
int count=0;

int main()
{
  int left, right;
  int i, j, k;

  //read S
  scanf("%d", &n);
  for(i=0; i<n; i++)scanf("%d", &S[i]);

  //Sort
  left=0;
  right=n;
  merge_sort(S, left, right);

  //print
  printf("%d ", S[0]);
  for(i=1; i<n-1; i++)  printf("%d ", S[i]);
  printf("%d\n%d\n", S[n-1], count);
  return 0;
}

//Marge method
void merge(int S[], int left, int mid, int right)
{
  int i, j, k;
  int n1=mid-left;
  int n2=right-mid;
  int L[LEN], R[LEN];

  for(i=0; i<n1; i++)L[i]=S[left+i];
  for(i=0; i<n2; i++)R[i]=S[mid+i];

  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left; k<right; k++)
    {
      if(L[i]<=R[j])
        {
          count++;
          S[k]=L[i];
          i++;
        }
      else 
        {
          count++;
          S[k]=R[j];
          j++;
        }
    }
}

void merge_sort(int S[], int left, int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      merge_sort(S, left, mid);
      merge_sort(S, mid, right);
      merge(S, left, mid, right);
    }
}
