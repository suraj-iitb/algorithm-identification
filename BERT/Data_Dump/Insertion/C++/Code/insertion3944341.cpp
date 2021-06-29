#include<stdio.h>
inline void isort(int *a, int n)
{
	for(int k=0;k<n;++k) printf("%d%c", a[k],k==n-1?'\n':' ');
	for(int i=1;i<n;++i)
	{
		int t=a[i];
		int j=i-1;
		for(;j>=0 && a[j]>t; --j)
			a[j+1]=a[j];
		a[j+1]=t;
		for(int k=0;k<n;++k) printf("%d%c", a[k],k==n-1?'\n':' ');
	}
}
int main()
{
	const int maxn=105;
	int a[maxn],n;
	scanf("%d", &n);
	for(int i=0;i<n;++i) scanf("%d", &a[i]);
	isort(a, n);
	return 0;
}
