#include<stdio.h>
#include<math.h>

#define MAX 500000
#define numMAX 1000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;

int main()
{
  int n,i,S[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&S[i]);
    }

  mergeSort(S,0,n);

  for(i = 0 ; i < n ; i++)
    {
      printf("%d",S[i]);
      if(i < n-1) printf(" ");
    }

  printf("\n%d\n",count);

  return 0;
}

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,L[mid - left + 1],R[right - mid + 1],i,j,k,lc=0,rc=0;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0 ; i < n1 ; i++)
    {
      L[i] = A[left + i];
      lc++;  /* leftの要素のカウント */
    }
  
  for(i = 0 ; i < n2 ; i++)
    {
      R[i] = A[mid + i];
      rc++;  /* rightの要素のカウント */
    }

  L[n1] = INFINITY;
  R[n2] = INFINITY;

  i = 0;
  j = 0;

  for(k = left ; k < right ; k++)
    {
      
      count++;
      
      if(L[i] <= R[j])
	{
	  lc--;
	  A[k] = L[i];
	  L[i] = numMAX;  /* 比べ終わったら最大値を代入 */
	  if(lc > 0) i++;  /* leftがまだあるなら */
	}
	    
      else
	{
	  rc--;
	  A[k] = R[j];
	  R[j] = numMAX;  /* 比べ終わったら最大値を代入 */
	  if(rc > 0) j++;  /* rightがまだあるなら */
	}
    }

  return;
}

void mergeSort(int A[],int left,int right)
{
  int mid;

  if(left + 1 < right)
    {
      mid = (left + right) / 2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
  return;
}

