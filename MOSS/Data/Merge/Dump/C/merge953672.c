#include<stdio.h>
#define MAX 500000
int sort_num=0;
void Marge(int * ,int,int,int);
void MargeSort(int * ,int,int);
int main()
{
  int n,S[MAX],N[MAX];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      //printf("%d\n",S[i]);
    }
  MargeSort(S,0,n);
  for(i=0;i<n;i++)
    {
      if(i!=n-1) printf("%d ",S[i]);
      else printf("%d\n",S[i]);
    }
  printf("%d\n",sort_num);
  return 0;
}

void Marge(int *S,int left,int mid ,int right)
{
  int i,j,k;
  int  n1 = mid-left;
  int  n2 = right-mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++)
    {
      L[i]=S[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i]=S[mid+i];
    }
  i=0;
  j=0;
  L[n1]=-1;
  R[n2]=-1;
  for(k=left;k<right;k++)
    {
      sort_num++;
      if(R[j]==-1)
	{
	  S[k]=L[i];
	  i++;
	  continue;
	}
      if(L[i]==-1)
	{
	  S[k]=R[j];
	  j++;
	  continue;
	}
      if(L[i]<=R[j])
	{
	  S[k]=L[i];
	  i++;
	}
      else
	{
	  S[k]=R[j];
	  j++;
	}
    }
}

void MargeSort(int *S,int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      MargeSort(S,left,mid);
      MargeSort(S,mid,right);
      Marge(S,left,mid,right);
    }
}
