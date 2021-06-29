#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
int c[10005];
int a[2000005],b[2000005],n;
void CountingSort()
{
	mem(c,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=10005;i++)
	{
		c[i] = c[i]+c[i-1];
	}
	for(int i=n;i>0;i--)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
}
int main()
{
	cin>>n;
	CountingSort();
	for(int i =1;i<=n;i++)
	{
		if(i>1)
		cout<<' ';
		cout<<b[i];
	}
	cout<<endl;
	return 0;
	
	
}






