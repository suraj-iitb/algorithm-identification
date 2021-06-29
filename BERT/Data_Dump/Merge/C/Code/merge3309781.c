#include <stdio.h>
#include <stdlib.h>


void merge(int[],int,int,int);
void Sort(int[],int,int);


int count = 0;

int main()
{
  int i,n,S[500000];
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  Sort(S,0,n);
  for(i = 0;i < n;i++)
    {
      if(i >0) printf(" ");
      printf("%d",S[i]);
    }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
void merge(int S[],int left,int mid,int right)
{
  int i,j,k,n1,n2;
  int *L,*R;
  n1 = mid - left;
  n2 = right - mid;
  L = (int *)malloc(sizeof(int)*(n1 + 1));
  R = (int *)malloc(sizeof(int)*(n2 + 1));
  for(i = 0;i <= n1 - 1;i++)
    {
      L[i] = S[left + i];
    }
  for(i = 0;i <= n2 - 1;i++)
    {
      R[i] = S[mid + i];
    }
  L[n1] = R[n2] = 2000000000;
  i = 0;
  j = 0;
  for(k = left;k <= right - 1;k++)
    {
      count++;
      if(L[i] <= R[j])
	{
	  S[k] = L[i];
	  i++;
	} else
	{
	  S[k] = R[j];
	  j++;
	}
    }
  free(L);
  free(R);
}
void Sort(int S[],int left,int right)
{
  int i,mid;
  if(left + 1 < right)
    {
      mid = (left + right) / 2;
      Sort(S,left,mid);
      Sort(S,mid,right);
      merge(S,left,mid,right);
    }
    
}
	  

