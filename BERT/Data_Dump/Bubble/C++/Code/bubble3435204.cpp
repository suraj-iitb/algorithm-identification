#include <iostream>
using namespace std;

int main()
{
	int N, a[100];
	cin >> N;
	for(int i = 0 ; i < N; ++i)
	{
		cin >> a[i];
	}
	
	int swap = 0;
	for(int i = 0; i < N - 1; ++i)
	{
		for(int j = N - 1; j > i; --j)
		{
			if(a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				
				++swap;
			}
		}
	}
	
	for(int i = 0 ; i < N; ++i)
	{
		if(i != 0)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl << swap << endl;

    return 0;
}

