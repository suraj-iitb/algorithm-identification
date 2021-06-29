#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[2000000] = { 0 }, b[2000000] = { 0 };

void CountSort(int k)
{
	int i, j;
	int c[10001] = { 0 };

	for (j = 0; j != k; ++j)
	{
		c[a[j]]++;
	}

	for (i = 1; i != 10001; ++i)
	{
		c[i] += c[i - 1];
	}

	for (j = k-1; j != -1; --j)
	{
		c[a[j]]--;
		b[c[a[j]]] = a[j];
		
	}
}




int main()
{
	int n;

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}

	CountSort(n);

	for (int i = 0; i != n; ++i)
	{
		if (i)
		{
			cout << " ";
		}
		cout << b[i];
	}
	cout << endl;

	return 0;

}
