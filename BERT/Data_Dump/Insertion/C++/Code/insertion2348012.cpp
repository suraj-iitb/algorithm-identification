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
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(m[j] < m[j-1])
			{
				int temp = m[j];
				m[j] = m[j-1];
				m[j-1] = temp;
			}
			else
				break;
		}
		cout<<m[0];
		for(int k = 1; k <n; k++)
			cout<<" "<<m[k];
		cout<<endl;
	}
}
