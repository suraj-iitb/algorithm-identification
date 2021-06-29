#include<iostream>
using namespace std;

void trace(int a[], int n)
{
  for ( int i = 0; i < n; i++ )
  {
    cout <<a[i];
	if ( i < n-1)
	{
		cout << " ";
	}
	else
	{
      cout << "\n";
	}
}
}
int main()
{	
	int n;
	int k=0;
	int a[100] = {0};
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> a[i];
	}

	trace (a, n);
	for ( int i = 1; i < n; i++)
	{
		for ( int j = i-1; j >= 0; j-- )
		{
			if ( a[j+1] < a[j] )
			{
				k = a[j+1];
			    a[j+1] = a[j];
				a[j] = k;
			}
		}
		trace (a, n);
	}
	return 0;
}
