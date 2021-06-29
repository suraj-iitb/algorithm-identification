#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void temp(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int counter = 0;
	bool flag = true;
	for (int i = 0; i < n && flag; ++i)
	{
		flag = false;
		int min = a[i];
		int min_n = i;
		for (int j = i+1; j < n; ++j)
		{
			if(min > a[j])
			{
				min = a[j];
				min_n = j;
			}
			if(a[j-1] > a[j])
				flag = true;
		}
		if(i != min_n)
		{
			temp(&a[i],&a[min_n]);
			counter++;
		}
	}
	for (int i = 0; i < n-1; ++i)
		cout << a[i] << " ";
	cout << a[n-1] << endl;
	cout << counter << endl;

	return 0;
}
