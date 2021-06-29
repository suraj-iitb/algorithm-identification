#include<stdio.h>
#include<stdlib.h>

#define INFTY 1000000000

void merge();
void mergeSort();
long *S;
int count=0;

int main()
{
  int n,i;
  int left,right;
  
  scanf("%d",&n);
  S=(long *)malloc((n)*sizeof(long));

  for(i=0;i<n;i++)
  {
    scanf("%ld",&S[i]);
  }

  left=0;
  right=n;

  mergeSort(left,right);
  for(i=0;i<n-1;i++) printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",count);

  free(S);

  return 0;
}

void mergeSort(int left,int right)
{
  int mid;
  if((left+1)<right)
    {
      mid=(left+right)/2;
      mergeSort(left,mid);
      mergeSort(mid,right);
      merge(left,mid,right);
    }
}

void merge(int left,int mid,int right)
{
  int n1,n2,i,j,k;
  long *L,*R;

  n1=mid-left;
  n2=right-mid;

  L=(long *)malloc((n1+1)*sizeof(long));
  R=(long *)malloc((n2+1)*sizeof(long));

  for(i=0;i<n1;i++) L[i]=S[left+i];
  for(i=0;i<n2;i++) R[i]=S[mid+i];

  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;

  for(k=left;k<right;k++)
    {
      if(L[i]<=R[j])
	{
	  S[k]=L[i];
	  count++;
	  i++;
	}
      else
	{
	  S[k]=R[j];
	  count++;
	  j++;
	}
    }

  
}
