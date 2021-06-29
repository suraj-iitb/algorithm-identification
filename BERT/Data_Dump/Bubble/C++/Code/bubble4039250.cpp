#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	///////////////////////////////////////////////////////////
	int t = 0;
	while (true)
	{
		int end = n;
		int lastsort = 1;
		for (int i = 0; i < end - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				t++;
				lastsort = i + 1;
			}
		}
		if (lastsort == 1)
			break;
		end = lastsort;

	}















	/////////////////////////////////////////////////////////////////


	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << a[i] << endl;
		else
			cout << a[i] << " ";
	}

	cout << t << endl;

















	delete[] a;
	return 0;
}
