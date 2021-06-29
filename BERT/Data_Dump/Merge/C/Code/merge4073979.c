#include<stdio.h>
#include<math.h>

#define N 500000
void marge(int *,int ,int ,int );
void margeSort(int *,int ,int );

int left,right,mid,cnt=0;

int main()
{
  int n,x,S[N];

  scanf("%d",&n);
  for(x=0;x<n;x++)
    {
      scanf("%d",&S[x]);
    }
  margeSort(S,0,n);

  for(x=0;x<n;x++)
    {
      if(x>0)printf(" ");
      printf("%d",S[x]);
    }
  printf("\n%d\n",cnt);
  return 0;
}



void marge(int S[],int left,int mid,int right)
{
  int i,j,k,n1,n2;
  int L[N/2+2],R[N/2+2];
  
  n1=mid-left;
  n2=right-mid;

  //L[0...n1],R[0...n2]を作成
  for(i=0;i<n1;i++)
    {
      L[i]=S[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i]=S[mid+i];
    }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;

  for(k=left;k<right;k++)
    {
      cnt++;
      if(L[i]<=R[j])
	{
	  S[k]=L[i];
	  i=i+1;
	}
      
      else
	{
	  S[k]=R[j];
	  j=j+1;
	}
	    
    }
}

void margeSort(int S[],int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      margeSort(S,left,mid);
      margeSort(S,mid,right);
      marge(S,left,mid,right);
    }
}

