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
	
	int sum = 0;
	int temp = 0;

	for (int i= 0; i < n-1; i++ )
	{
		int mini = i;
		for ( int j = i+1; j < n; j++ )
		{
			if ( a[j] < a[mini] )
			{
				mini = j;
			}
		}
		if ( mini != i)
		{
				temp = a[i];
				a[i] = a[mini];
				a[mini] = temp;
				sum++;
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
