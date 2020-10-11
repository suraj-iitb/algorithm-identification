#include<stdio.h>
#include<limits.h>

typedef struct{
  char moji;
  int kazu;
}Card;

int partition(Card *,int,int,int);
void marge(Card *,int,int,int);
void mergesort(Card *,int,int,int);
void quicksort(Card *,int,int,int);
Card L[100000],R[100000];

int main()
{
  int n,i,N,stable=1;
  Card A[100000],B[100000];
  char S[10];
  
    scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf(" %c",&S);
      scanf("%d",&N);
      A[i].moji=B[i].moji=S[0];
      A[i].kazu=B[i].kazu=N;
    }
  mergesort(A,n,0,n);
  quicksort(B,n,0,n-1);
  for(i=0;i<n;i++)
    {
      if(A[i].moji!=B[i].moji)
	stable=0;
  }
  if(stable==1)
     printf("Stable\n");
      else printf("Not stable\n");
  for(i=0;i<n;i++)
    {
      printf("%c %d\n",B[i].moji,B[i].kazu);
    }
  return 0;
}

int partition(Card *A,int n,int p,int r)
{
  int i,j;
  Card x,a;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++)
    {
      if(A[j].kazu<=x.kazu)
	{
	  i++;
	  a=A[i];
	  A[i]=A[j];
	  A[j]=a;
	}
    }
	  a=A[i+1];
	  A[i+1]=A[r];
	  A[r]=a;
	  return i+1;
    }

void merge(Card *A,int left,int mid,int right)
{
  int i,j,k;
  int n=mid-left;
  int m=right-mid;
  for(i=0;i<n;i++)
    L[i]=A[left+i];
    for(i=0;i<m;i++)
      R[i]=A[mid+i];
    L[n].kazu=R[m].kazu=INT_MAX;
    i=0;
    j=0;
    for(k=left;k<right;k++)
      {
	if(L[i].kazu<=R[j].kazu)
	  {
	    A[k]=L[i++];
	  }
	else
	  {
	  A[k]=R[j++];
	  }
      }
}




void mergesort(Card *A,int n,int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergesort(A,n,left,mid);
      mergesort(A,n,mid,right);
      merge(A,left,mid,right);
    }
}
    
void quicksort(Card *A,int n, int p,int r)
    {
      int q;
      if(p<r)
	{
	  q=partition(A,n,p,r);
	   quicksort(A,n,p,q-1);
	   quicksort(A,n,q+1,r);
	}
    }
  


  




