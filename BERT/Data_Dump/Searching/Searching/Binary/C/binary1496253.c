#include<stdio.h>
int main(void)
{
	int N[100000]={0},i,m,n,q,l,r,mid,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&q);
		N[i]=q;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		l=0;r=n;
		scanf("%d",&q);
		while(l<r)
		{
			mid=(l+r)/2;
			if (N[mid]==q) {c++;break;}
			else if (q<N[mid]) {r=mid;}
			else {l=mid+1;}
		}
	}
	printf("%d\n",c);
	return 0;
}
