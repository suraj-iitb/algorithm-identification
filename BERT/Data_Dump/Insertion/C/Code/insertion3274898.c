#include <stdio.h>

#define N 100

void insertionSort(int *, int);

int main()
{
  int i,n;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
        if(i!=n-1)
        printf(" ");
      }
      printf("\n");
  insertionSort(A,n);
}

void insertionSort(int *a,int n)
{
  int i,j,k,v;
  for(i=1;i<=n-1;i++)
    {
      v = a[i];
      j = i - 1;
      while((j >= 0) && (a[j] > v))
        {
          a[j+1] = a[j];
          j--;
        }
      a[j+1] = v;
      for(k=0;k<n;k++)
      {
          printf("%d",a[k]);
          if(k!=n-1)
          printf(" ");
        }
      printf("\n");
    }

}
