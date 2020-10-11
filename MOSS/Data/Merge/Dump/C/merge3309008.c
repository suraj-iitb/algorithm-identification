#include<stdio.h>
#define INFTY 500000
int R[1000000],L[1000000],C=0;
void merge(int *,int, int,int );
void mergeSort(int *,int,int);

int main()
{
  int S[1000000],i,n,left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      if(n<=500000)
        {
          scanf("%d",&S[i]);
        }
    }
  left=0;
  right=n;
  
  mergeSort(S,left,right);

  for(i=0;i<n;i++)
    {
       printf("%d",S[i]);
      if(i<n-1)
        {
          printf(" ");
        }
      if(i==n-1)
        {
          printf("\n");
        }
    }
  printf("%d\n",C);
    
  return 0;
}
void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k,l=0,r=0;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<=n1-1;i++)
    {
      L[i]=A[left+i];
      l++;
    }
  
  for(i=0;i<=n2-1;i++)
    {
      R[i]=A[mid+i];
      r++;
    }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++)
    {
      C++;
      if(L[i]<=R[j])
        {
          if(l>0)
            {
              A[k]=L[i];
              i=i+1;
              l--;
            }
          else
            {
            A[k]=R[j];
            j=j+1;
            r--;
        }
        }
      else
        {
          if(r>0)
            {
          A[k]=R[j];
          j=j+1;
          r--;
            }
          else
            {
              A[k]=L[i];
          i=i+1;
          
                    l--;
            }
        }
    }
}
  
void mergeSort(int A[],int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}

