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
		int m = i;
		for(int j = i + 1; j < N; ++j)
		{
			if(a[j] < a[m])
			{
				m = j;
			}
		}
		
		if(m != i)
		{
			int temp = a[m];
			a[m] = a[i];
			a[i] = temp;
			
			++swap;
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

