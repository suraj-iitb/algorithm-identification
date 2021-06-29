#include<stdio.h>


#define MAX 500000
#define SENTINEL 2000000000

int LEFT[MAX/2+2],RIGHT[MAX/2+2];
int c;

void marge(int A[],int n,int left, int mid, int right)
{
  int i,j=0,g,n1,n2;
   n1 = mid -left;
   n2 = right - mid;
  for ( i = 0; i < n1; i++) LEFT[i]  =  A[left + i];
  for ( i = 0; i < n2; i++) RIGHT[i] =  A[mid  + i];
  LEFT[n1] = RIGHT[n2] = SENTINEL;
  i=0;
 
  for(g = left; g < right; g++)
    {
      c++;
      if(LEFT[i] <= RIGHT[j])
	{
	  A[g] = LEFT[i++];
	}
      else
	{
	  A[g] = RIGHT[j++];
	}
    }
}

void margesort(int A[],int n, int left, int right)
{
  int mid;
  if(left+1<right)
    {
      mid = (left + right)/2;
      margesort(A,n,left,mid);
      margesort(A,n,mid,right);
      marge(A,n,left,mid,right);
    }
}

int main()
{
  int A[MAX],n,i;
  c =0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  margesort(A,n,0,n);

  for(i=0;i<n;i++)
    {
      if(i)
	printf(" ");
      printf("%d",A[i]);
	
    }
  printf("\n");

  printf("%d\n",c);

  return 0;
}
    
      

