#include<iostream>
using namespace std;
void insert(int a[],int n) {
	int key;
	for (int k = 0; k < n - 1; k++)
		cout << a[k] << " ";
	cout << a[n - 1] << endl;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		for (int k = 0; k < n - 1; k++)
			cout << a[k] << " ";
		cout << a[n - 1] << endl;
	}
}
int main()
{
	int n;
	int a[200];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		insert(a, n);
	}
	
    return 0;
}
