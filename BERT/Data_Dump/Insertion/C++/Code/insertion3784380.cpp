#include<iostream>
#include<algorithm>

using namespace std;
static const int LENGTH =200;

int main()
{
	
	int A[LENGTH];
	int n;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	for(int m = 0; m < n; ++m)
	{
		cout << A[m];
		if(m != n - 1)
		{
			cout << " ";
		}
	}
			cout << endl;
			
	for(int i = 1; i < n; ++i)
	{
		int value = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > value)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = value;
		
		for(int m = 0; m < n; ++m)
		{
			cout << A[m];
			if(m != n - 1)
			{
				cout << " ";
			}
		}
			cout << endl;
	}
	
	
	return 0;
}
