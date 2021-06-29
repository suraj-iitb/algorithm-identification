#include<stdio.h>
int a[100001],n;
int dddd(int q); 
int main()
{
	int s[50001],z,x=0,i,j,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&s[i]);
		if(dddd(s[i]))	
		{
			x++;
		}
	}
printf("%d\n",x); 
	return 0;
}
int dddd(int q)
{
	int v=n,b=0,c;
	 while(v>b)
	{
		c=(v+b)/2;
		if(a[c]==q)
		return 1;
		if(a[c]<q)
		b=c+1;
		else if(a[c]>q)
		v=c;
	 } 
	 return 0;
}
