#include<stdio.h>
#include<stdlib.h>

void CountingSort(int *,int *,int,int);

int main()
{
  int *a,*b;
  int n,i,k;

  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  b=(int *)malloc(sizeof(int)*n);
  for( i=1 ; i<=n ; i++ )
    scanf("%d",&a[i]);
  k=a[1];
  for( i=1 ; i<=n ; i++)
  {
    if( k<a[i])
      k=a[i];  
  }  
  CountingSort(a,b,k,n);
  for( i=1 ; i<=n ; i++ )
  {
    if(i==n) printf("%d\n",b[i]);
    else printf("%d ",b[i]);
  }  
  return 0;
}

void CountingSort(int *a,int *b,int k,int n)
{
  int i,j,c[10000];
  for( i=0 ; i<=k ; i++ )
    c[i]=0;
  for( j=1 ; j<=n ; j++ )
    c[a[j]]++;
  for( i=1 ; i<=k ; i++ )
    c[i]=c[i]+c[i-1];
  for( j=n ; j>0 ; j-- )
  {
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }  
}

