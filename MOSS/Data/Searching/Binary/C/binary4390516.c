#include<stdio.h>
void selection_sort(int A[],int n)
{
  int i,j,tmp;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(A[i]>A[j])
      {
        tmp=A[i];
        A[i]=A[j];
        A[j]=tmp;
      }
    }
  }
}
int binarySearch(int A[],int n,int key)
{
  int left,right,mid;
  left=0; right=n;
  while(left<right)
  {
    mid=(left+right)/2;
    if(A[mid]==key) return 1;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }
  return 0;
}
int main(void)
{
  int n,i,q,count=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++) scanf("%d",&T[i]);
 // selection_sort(S,n);
  for(i=0;i<q;i++)
  {
    count+=binarySearch(S,n,T[i]);
  }
  printf("%d\n",count);
  return 0;
}

