#include<stdio.h>
int main()
{
	int n,i,j,flag,sum = 0,t;
	int a[100];
	scanf("%d",&n);
	for (i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	
	flag = 1;
	while(flag) 
	{
		flag = 0;
		for (i = n-1 ; i > 0 ; i--)
		{
			if (a[i] < a[i-1])
			{
				t = a[i];
				a[i] = a[i-1];
				a[i-1] = t;
				sum+=1;
				flag = 1;
			}
		}
	}
	for (i = 0 ; i < n ; i++) 
	{
	    if(i != n-1)
	    {
		  printf("%d ",a[i]);
	    }
	    else
	    {
	        printf("%d\n",a[i]);
	    }
	}
	printf("%d\n",sum);
    return  0;
}
