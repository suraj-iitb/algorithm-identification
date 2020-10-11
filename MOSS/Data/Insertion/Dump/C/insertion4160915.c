#include<stdio.h>
int main()
{
	int n,i,j,t;
	int a[100];
	scanf("%d",&n);
	for (i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}
	
	for (i = 1 ; i < n ; i++)
	{
	    for (j = 0 ; j < n ; j++)
		{
			if (j == n-1)
			{
			    printf("%d\n",a[j]);
		    }
		    else
		    {
			    printf("%d ",a[j]);
		    }	 
	    }
		t = a[i];
		j = i-1;
		while(j >= 0 && a[j] > t)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
		/*for (j = 0 ; j < n ; j++)
		{
			if (j == n-1)
			{
			    printf("%d\n",a[j]);
		    }
		    else
		    {
			    printf("%d ",a[j]);
		    }	 
	    }*/
    }
    for (j = 0 ; j < n ; j++)
		{
			if (j == n-1)
			{
			    printf("%d\n",a[j]);
		    }
		    else
		    {
			    printf("%d ",a[j]);
		    }	 
	    }
    return 0;
}
