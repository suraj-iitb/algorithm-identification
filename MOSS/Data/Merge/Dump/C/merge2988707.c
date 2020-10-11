#include <stdio.h>
int S[500000];
int count = 0;

int merge(int,int,int);
int mergeSort(int,int);

int main()
{

  int n,i;
  scanf("%d",&n);

  for(i=0 ; i<n;i++)scanf("%d",&S[i]);
  mergeSort(0, n);
  for(i = 0 ; i<n ; i++)
    {
      if(i == n-1)
	{
	  printf("%d",S[i]);
	  break;
	}
      printf("%d ",S[i]);

    }
  
  printf("\n%d\n",count);
}

merge(int left, int mid , int right)
{
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1] , R[n2];

  for(i = 0 ; i < n1 ; i++)L[i] = S[left + i];
  for(i = 0 ; i < n2 ; i++)R[i] = S[mid +  i];
  L[n1] = 999999999;
  R[n2] = 999999999;

  i = 0;
  j = 0;

  for(k = left ; k <right ; k++)
    {
      
      if(L[i] <= R[j])
	{
	  S[k] = L[i];
	  i++;
	}
      else
	{
	  S[k] = R[j];
	  j++;
	}
      count++;
    }

}

mergeSort(left,right)
{
  int mid;
  
  if(left+1 < right)
    {
      mid =  (left + right)/2;
      mergeSort(left,mid);
      mergeSort(mid,right);
      merge(left,mid,right);
    }

}

