#include <iostream>

using namespace std;

int cut(int a[], int d) {
	for (size_t i = 0; i < d; i++)
	{
		if (i > 0) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	return 0;
}

int main()
{
	int amount;
	cin >> amount;
	int a[101];
	for (size_t i = 0; i < amount; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 1; i < amount; i++)
	{
		cut(a, amount);
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
	cut(a, amount);
	return 0;
}
