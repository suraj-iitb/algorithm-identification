#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;++i)
	{
		sort(a.begin(),a.begin()+i);
		for(int k=0;k<n;++k) 
			k>0 ? printf(" %d",a[k]) : printf("%d",a[k]);
		printf("\n");
	}
	return 0;
}
