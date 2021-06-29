#include<stdio.h>

int main()
{
  int n,i,j,k,key;
  int a[100];
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&a[i]);
  }
   for( k=0 ; k<n ; k++ )
    {
      if( k == n-1 )
      printf("%d\n",a[k]);
      else printf("%d ",a[k]);
    }
  for( i=1 ; i<=n-1 ; i++ )
  {
    key = a[i];
    j = i-1;
    while( j >= 0 && a[j] > key )
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1]=key;
     for( k=0 ; k<n ; k++ )
    {
      if( k == n-1 )
      printf("%d\n",a[k]);
      else printf("%d ",a[k]);
    }
  }
  return 0;
}  
