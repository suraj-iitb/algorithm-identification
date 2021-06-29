#include<stdio.h>
int main()
{
  int n,data[100],k=0,i,j,a;

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&data[i]);
  }
  for( i=0 ; i<n-1 ; i++ )
  {
    for( j=n-1 ; j >= i+1 ; j-- )
    {
      if( data[j] < data[j-1])
      {
         a=data[j];
         data[j]=data[j-1];
         data[j-1]=a;
         k++;
      }
        }
  }
    for( i=0 ; i<n ; i++ )
    {
      if( i==n-1 ) printf("%d\n",data[i]);
      else printf("%d ",data[i]);
    }
    printf("%d\n",k);
    return 0;
  }
