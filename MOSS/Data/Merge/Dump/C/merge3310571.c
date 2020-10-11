#include<stdio.h>
#define MAX 500000
#define NUMBER 1000000000

int Left[MAX/2+2],Right[MAX/2+2];
int count=0;

void Merge(int A[],int n,int left,int middle,int right)
{
  int i,j,l,m;
  n=middle-left;
  m=right-middle;
  for(i=0;i<n;i++) Left[i]=A[left+i];
  for(i=0;i<m;i++) Right[i]=A[middle+i];
  Left[n]=NUMBER;
  Right[m]=NUMBER;
  i=0;
  j=0;
  for(l=left;l<right;l++)
    {
      count++;
      if(Left[i]<=Right[j])
        {
          A[l]=Left[i++];
        }
      else
        {
          A[l]=Right[j++];
        }
    }
}

void MergeSort(int A[],int num, int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      MergeSort(A,num,left,mid);
      MergeSort(A,num,mid,right);
      Merge(A,num,left,mid,right);
    }
}
int main()
{
  int A[MAX],n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  MergeSort(A,n,0,n);

  for(i=0;i<n;i++)
    {
      if(i) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
  printf("%d\n",count);

  return 0;
}






