#include<bits/stdc++.h>

const int MAXN=110;

int main()
{
	int n,A[MAXN],cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]); 
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(A[j]<A[j-1])
			{
				std::swap(A[j],A[j-1]);
				cnt++;
			}
	for(int i=0;i<n;i++)
		printf("%d%c",A[i],i+1==n?'\n':' ');
	printf("%d\n",cnt);
	return 0;
}
