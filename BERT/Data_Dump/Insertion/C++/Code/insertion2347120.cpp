#include <iostream>

using namespace std;
int main()
{
	int n;
	int key;
	cin>>n;
	int a[100000];
	for (int i = 0; i < n; i++)
		cin>>a[i];
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		cout<<a[0];
		for (int k = 1; k < n; k++)
		{
				cout << " "<< a[k] ;
		}
		cout <<endl;
	}
	return 0;
}
