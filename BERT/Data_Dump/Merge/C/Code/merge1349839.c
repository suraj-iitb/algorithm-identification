#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define SENTINEL 1000000000

void mergesort( int,int);
void merge(int,int,int);

int A[N],count=0;
main()
{
  int left,right,mid,i,n;

  scanf("%d",&n);
 
  left = 0;
  right = n;
  mid = (left + right)/2;

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  mergesort(left,mid);  /*????????§DEVIDE??????*/
  mergesort(mid,right);
  merge(left,mid,right);

  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i == n-1)break;
      printf(" ");
    }
  printf("\n%d\n",count);
  return 0;
}


void mergesort(int l,int r )
{
  int m;

  if(l+1<r)
    {
      m = (l + r)/2;
      mergesort(l,m);
      mergesort(m,r);
      merge(l,m,r);
    }
}


void merge(int l,int m,int r)
{
  int n1,n2,k,j,i;
  int *L,*R;
  n1 = m - l;
  n2 = r - m;

  L = malloc(sizeof(int)*(n1+1));/*SENTINEL??????????????????????????????*/
  R = malloc(sizeof(int)*(n2+1));

  for(i=0;i<n1;i++)
    {
      L[i] = A[l+i];
    }

  L[n1] = SENTINEL;

  for(i=0;i<n2;i++)
    {
      R[i] = A[m+i];
    }

  R[n2] = SENTINEL;

  j = 0;
  k = 0;

  for(i=l;i<r;i++)
    {
      if(L[j] <=R[k])
	{
	  A[i] = L[j];
	  j++;
	  count++;
	}
      else
	{
	  A[i] = R[k];
	  k++;
	  count++;
	}

    }

}
