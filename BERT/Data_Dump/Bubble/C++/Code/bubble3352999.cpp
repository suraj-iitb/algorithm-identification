#include <cstdio>
#include <iostream>
// 使用flag的冒泡排序法 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	
	int count=0;
	int flag=1;
	for(int i=0;flag;i++)
	{
		flag=0;
		for(int j=n-1;j>=i+1;j--)
			if(a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
				flag=1;
				count++;	
			} 
	}
		
	for(int i=0;i<n;i++) 
	{
		if(i>0) cout<<' ';
		cout<<a[i];
	}
	cout<<'\n'<<count<<'\n';
	return 0;
}
