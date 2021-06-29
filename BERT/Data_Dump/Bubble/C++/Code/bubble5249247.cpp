#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100100];
bool flag = 1;
int cnt = 0;

int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	for (int i = 0; flag; i++)
	{
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = 1;
				cnt++;
			}
				
		}
	}

	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << a[i] << " ";
		else
			cout << a[i] << endl;
	cout << cnt << endl;

	return 0;
}

