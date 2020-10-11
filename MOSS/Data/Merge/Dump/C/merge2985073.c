#include"stdio.h"
#include"stdlib.h"
#define INFTY 1000000001

int C;

void marge(int *A,int left,int mid,int right)
{
  int n1=mid-left;
  int n2=right-mid;
  int *L=(int*)malloc(sizeof(int)*(n1+1));
  int *R=(int*)malloc(sizeof(int)*(n2+1));
  int i,j,k;
  for(i=0;i<n1;i++)
    {
      L[i]=A[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i]=A[mid+i];
    }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      C++;
      if(L[i]<=R[j])
        {
          A[k]=L[i];
          i++;
        }
      else
        {
          A[k]=R[j];
          j++;
        }
    }
}
void margeSort(int *A,int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      margeSort(A,left,mid);
      margeSort(A,mid,right);
      marge(A,left,mid,right);
    }
}
int main()
{
  int *S;
  int n;
  int i;
  C=0;
  scanf("%d",&n);
  S=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  margeSort(S,0,n);
  printf("%d",S[0]);
  for(i=1;i<n;i++)
    {
      printf(" %d",S[i]);
    }
  printf("\n%d\n",C);
}
