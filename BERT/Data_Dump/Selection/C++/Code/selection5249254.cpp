#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100100], minn, cnt;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		minn = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[minn])
				minn = j;
		}
		swap(a[i], a[minn]);
		if (i != minn)
			cnt++;
	}
	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << a[i] << " ";
		else
			cout << a[i] << endl << cnt << endl;

	return 0;

}
