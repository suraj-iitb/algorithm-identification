#include<stdio.h>
#define N 100
int main()
{
  int a[N],i,j,n,b,c=0;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
    }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	b=a[j];
	a[j]=a[j-1];
	a[j-1]=b;
	c++;
      }
    }
  }
  for(i=0;i<n-1;i++)
  printf("%d ",a[i]);

  printf("%d\n%d\n",a[n-1],c);
  return 0;
}

      
      
      
		    
    
    

