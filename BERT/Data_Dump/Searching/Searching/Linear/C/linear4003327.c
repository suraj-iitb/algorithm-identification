#include <stdio.h>
#include <math.h>

int main()
{
	int n,m,i,j,x,c=0;
	scanf("%d",&n);
	
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		
		for(j=0;j<n;j++){
			if(a[j]==x)
			{
				c=c+1;
				break;
			}
		}
	}
	
	printf("%d\n",c);
	
	return 0;
}
