#include<stdio.h>
int main(void)
{
	int a, b, c,m,j,e;
	e=0;
	scanf("%d",&a);
	int d[a];
		for(b=0;b<a; b++)
	{
		scanf("%d",&d[b]);
	}
	for(b=0;b<a; b++)
	{
		m=b;
		for(j=b; j<a; j++)
		{
			if(d[j]<d[m])
			{
				m=j;
			}
		}
			if(d[b]!=d[m])e++;
				c=d[b];
				d[b]=d[m];
				d[m]=c;
		
	}
	
	for( int b = 0; b < a; b++)
	{
		if(b != a-1) printf("%d ",d[b]);
			else{printf("%d\n",d[b]);}
	}
	
	printf("%d\n",e);
	return 0;
}
