#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int A[500000+10];
int n,i,j,sum=0;

int Merge(int A[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(i=0;i<n1;i++)
    {
        L[i]=A[left+i];
    }
    for(i=0;i<n2;i++)
    {
        R[i]=A[i+mid];
    }
    i=0;
    j=0;
    for(int k=left;k<right;k++)
    {
        if(L[i]<=R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
        sum++;
    }
}

int Merge_sort(int A[],int left,int right)
{
  if(left+1<right)
  {
   int mid=(left+right)/2;
   Merge_sort(A,left,mid);
   Merge_sort(A,mid,right);
   Merge(A,left,mid,right);
  }
}


int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Merge_sort(A,0,n);
    for(i=0;i<n;i++)
    {
      printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
    }
    printf("%d\n", sum);
    return 0;
}

