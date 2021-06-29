#include <iostream>

using namespace std;

void output(int in[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << in[i];
		if (i != n - 1)
			cout << " ";
	}
	cout << endl;
}

int main(void)
{
	int n;
	cin >> n;

	int a[103];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	output(a, n);

	for (int i = 1; i < n; i++)
	{
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		output(a, n);
	}

	return 0;
}
