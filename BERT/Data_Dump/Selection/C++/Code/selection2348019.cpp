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
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int Min = INF, loc = i;
		for(int j = i; j < n; j++)
		{
			if(m[j]<Min)
			{
				Min = m[j];
				loc = j;
			}
		}
		if(loc != i)
			ans++;
		int temp = m[i];
		m[i] = m[loc];
		m[loc] = temp;
	}

	cout<<m[0];
	for(int i = 1; i < n; i++)
		cout<<" "<<m[i];
	cout<<endl<<ans<<endl;
	return 0;
}
