#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v[i] = t;
	}
	bool flag = true;
	int i = 0;
	int ans = 0;
	while (flag)
	{
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--)
		{
			if (v[j] < v[j -1])
			{
				swap(v[j], v[j - 1]);
				flag = 1;
				ans++;
			}
		}
		i++;
	}
	for (int j = 0; j < n; j++)
	{
		cout << v[j];
		if (j != n - 1)
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}
