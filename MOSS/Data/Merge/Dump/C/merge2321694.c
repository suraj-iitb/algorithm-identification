#include<stdio.h>
#define MAX 500000
#define INFTY 2000000000

int Left[MAX/2+2],Right[MAX/2+2];
int cnt,A[MAX];

void merge(int A[],int l,int m , int r)
{
  int i,j,n1,n2,k;
   n1 = m - l;
   n2 = r - m;
   for(i=0;i < n1;i++)
     {
       Left[i]=A[l+i];
     }
 
   for(i=0;i < n2;i++)
     {
       Right[i]=A[m+i];
     }
   Left[n1]=INFTY;
   Right[n2]=INFTY;
   i=0;
   j=0;
   for(k=l;k < r;k++)
     {
       cnt++;
       if(Left[i]<=Right[j])
	 {
	   A[k] = Left[i];
	   i++;
	 }
       else 
	 {
	 A[k] = Right[j];
	 j++;
	 }
     }
}

void mergeSort(int A[],int l, int r)
{
  int mid=0;
  if(l+1 < r)
    {
      mid = (l+r)/2;
      mergeSort(A,l,mid);
      mergeSort(A,mid,r);
      merge(A,l,mid,r);
    }
}

int main()
{
  int n,i;
  cnt = 0;
  scanf("%d",&n);
  for (i=0;i < n;i++)
    {
      scanf("%d",&A[i]);
    }

  mergeSort(A,0,n);

  for(i = 0; i < n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;
}
