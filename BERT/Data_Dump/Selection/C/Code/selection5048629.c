#include<stdio.h>
int main()
{
  int i,j,n,data[100],k=0,min,a;
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&data[i]);
  }
  for( i=0 ; i<n ; i++ )
  {
    min=i;
    for( j=i ; j<n ; j++)
    {
      if( data[j]<data[min])
      {
	min=j;
      }
    }
    if( data[i]!=data[min])
    {
      k++;
      a=data[i];
      data[i]=data[min];
      data[min]=a;
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

