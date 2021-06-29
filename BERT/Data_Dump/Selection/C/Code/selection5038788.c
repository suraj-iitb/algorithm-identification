#include <stdio.h>

int main()
{
	int n,a[100];
	scanf("%d",&n);
	
	for(int i=0;i<300;i++)
	scanf("%d",&a[i]);
  
	int count=0;
    for(int i=0;i<n;i++)
    {
    	int min=i;
    	for(int t=i;t<n;t++)
    	 if(a[t]<a[min])min=t;
    	if(min>i)
    	{
    		count++;
    		int temp=a[min];
    		a[min]=a[i];
    		a[i]=temp;
    	}
    	
    	
    }
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i<n-1)printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}

