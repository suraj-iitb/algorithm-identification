#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int n, m[105];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> m[i];
	int flag = 1;
	int ans = 0;
	while(flag)
	{
		flag = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(m[i] > m[i+1])
			{
				int temp = m[i];
				m[i] = m[i+1];
				m[i+1] = temp;
				ans++;
				flag = 1;
			}
		}
	}
	cout<<m[0];
	for(int i = 1; i < n; i++)
		cout<<" "<<m[i];
	cout<<endl<<ans<<endl;
	return 0;
}
