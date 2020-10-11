#include<stdio.h>
#define N 1000000
#define INF 2000000000

void merge(int [], int, int, int);
void mergeso(int [], int, int);

int count=0,n;
int A[N];


int main()
{
  int i,l=0,m,r;

  scanf("%d",&n);
  r=n;
  
  for(i=0; i<n; i++) scanf("%d",&A[i]);
  
  mergeso(A,l,r);
   
  for(i=0; i<n; i++)
    {
      printf("%d",A[i]);
      if(i!=n-1)printf(" ");
    }
  printf("\n");
  printf("%d\n",count);
    

  return 0;
}

void merge(int A[], int l, int m, int r)
{
  int n1,n2,L[N],R[N],k,i,j;

  
  n1=m-l;
  n2=r-m;

  for(i=0; i<n1; i++) L[i]=A[l+i];
  L[n1]=INF;
  for(i=0; i<n2; i++) R[i]=A[m+i];
  R[n2]=INF;
  i=0;
  j=0;

  for(k=l; k<r; k++)
    {
      
      if(L[i]<=R[j])
	{
	  A[k]=L[i];
	  i++;
	  count++;
	}
      else
	{
	  A[k]=R[j];
	  j++;
	  count++;
	}
    }
  
}

void mergeso(int A[], int l, int r)
{
  int m;
  if(l+1<r)
    {
      m=(l+r)/2;
      mergeso(A,l,m);
      mergeso(A,m,r);
      merge(A,l,m,r);
    }
}
  
  

