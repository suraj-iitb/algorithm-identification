#include <stdio.h>
#define N 5000000
int count = 0;
void merge(int* A, int left, int mid, int right)
{
  int i,j,k,n1,n2,L[N],R[N];
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++)
    L[i] = A[left+i];
  for(i = 0; i < n2; i++)
    R[i] = A[mid+i];
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;
  for(k = left; k < right; k++)
    {
      count++;
      if(L[i] <= R[j])
	{
	  A[k] = L[i];
	  i++;
	}
      else 
	{
	  A[k] = R[j];
	  j++;
	}
    }
}

int* mergeSort(int* A, int left, int right)
{
  int mid;
  if(left+1 < right)
    {
      mid = (left+right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);      
    }
  return A;
}

  
      
	
  
  
int main()
{
  int n,i,S[N],left = 0,right,*s;
  scanf("%d",&n);
  right = n;
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  s = mergeSort(S, left, right);
  for(i = 0; i < n; i++)
    {
      printf("%d",s[i]);
      if(i != n - 1) printf(" ");
    }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

