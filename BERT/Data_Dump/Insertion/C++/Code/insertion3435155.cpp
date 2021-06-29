#include <iostream>
using namespace std;

void out(int *a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(i != 0)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
}

int main()
{
    int N, a[100];
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >>a[i];
	}
	
	out(a, N);
	for(int i = 1; i < N; ++i)
	{
		int key = a[i], j = i - 1;
		while(j >= 0 && a[j] >= key)
		{
			a[j + 1] = a[j];
			--j;
		}
		
		a[j + 1] = key;
		out(a, N);
	}

    return 0;
}

