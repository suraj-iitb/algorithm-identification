#include<stdio.h>

#define N 500000

void mergeSort(int [ ], int , int);

int cnt=0,n,s[N];

int main()
{
  int i,S[N];

  while(1)
    {
      scanf("%d",&n);
      if(n <= N && n > 0) break;
    }

  for(i=0;i<n;i++)
      scanf("%d",&S[i]);

  mergeSort(S,0,n-1);

  for(i=0;i<n-1;i++)
    printf("%d ",S[i]);
  
  printf("%d\n%d\n",S[i],cnt);
  
  return 0;
}

void mergeSort(int A[ ], int left, int right)
{
  int mid,i,j,k;
  if(left < right)
    {
      mid = (left + right) / 2;
      mergeSort(A,left,mid);
      mergeSort(A,mid+1,right);

      for (i = left; i <= mid; i++)
        s[i] = A[i];
      
      for (i = mid + 1, j = right; i <= right; i++, j--)
        s[i] = A[j];
      
      i = left;         
      j = right;       
    
      for (k = left; k <= right; k++)
	{
	  if (s[i] <= s[j])        
	    A[k] = s[i++];
	  else
	    A[k] = s[j--];
	  cnt++;
	}
    }
}


