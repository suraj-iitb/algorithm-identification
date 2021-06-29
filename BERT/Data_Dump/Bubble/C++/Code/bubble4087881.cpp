#include <iostream>
using namespace std;

#define MAX_SIZE 100

int main()
{
	int a[MAX_SIZE+1];
	int n, cnt = 0;
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= (n-i); j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				cnt++;
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(i - 1) cout << " ";
		cout << a[i];
	}

	cout << endl << cnt << endl;
	return 0;
}
