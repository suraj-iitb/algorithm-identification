#include<iostream>
using namespace std;

int main()
{	
	int n;
	int a[100] = {0};
	cin >> n;
	for ( int i = 0; i < n; i++)
	{ 
		cin >> a[i];
	}
	
	int temp = 0;
	int sum = 0;

	for (int i= 0; i < n-1; i++ )
	{
		for ( int j = 0; j < n-1-i; j++ )
		{
			if ( a[j] > a[j+1] )
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				sum++;
			}
		}
	}

	for ( int i= 0; i < n; i++ )
	{
	cout << a[i];
	if ( i < n-1 )
	{
		cout << " ";
	}
	}

	cout << "\n" << sum << endl;

	return 0;
}
