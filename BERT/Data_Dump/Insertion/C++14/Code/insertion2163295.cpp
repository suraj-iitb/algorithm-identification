#include<bits/stdc++.h>

using namespace std;

const int MAXN=200;

int main()
{
	int n,A[MAXN];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
	{
		int key=A[i],j=i-1;
		while(j>=0&&A[j]>key)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		for(int k=0;k<n;k++)
			printf("%d%c",A[k],k+1==n?'\n':' ');
	}
	return 0;
}
