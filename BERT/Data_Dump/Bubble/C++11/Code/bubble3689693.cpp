#include<iostream>

using namespace std;
int main()
{	
	int a[100];
	int N,m,cnt=0;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>a[i];
	}
	int i=0,j,flag=1;
	while(flag)
	{
		flag=0;
		
		for ( j = N-1; j >=i+1; --j)
		{
			if (a[j-1]>a[j])
			{
				m=a[j-1];
				a[j-1]=a[j];
				a[j]=m;
				++cnt;
				flag=1;

			}
		}

	}
	for (int i = 0; i < N; ++i)
	{
		if (i==N-1)
		{
			cout<<a[i]<<endl;
		}
		else cout<<a[i]<<" ";
	}
	cout<<cnt<<endl;
	return 0;
}
