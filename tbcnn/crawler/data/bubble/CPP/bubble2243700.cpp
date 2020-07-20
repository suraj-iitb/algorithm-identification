#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int dataset;
	cin >> dataset;
	int a[100];
	for (int i = 0; i < dataset; i++)
	{
		cin >> a[i];
	}
	int flag = 1;
	int kaisuu = 0;
	while (flag) {
		flag = 0;
		for (int i = 1; i < dataset; i++)
		{
			if (a[i - 1] > a[i]) {
				int z = a[i - 1];
				a[i - 1] = a[i];
				a[i] = z;
				flag = 1;
				kaisuu++;
			}
		}
	}
	for (int i = 0; i < dataset; i++)
	{
		if (i > 0) {
			cout << " " << a[i];
		}
		else {
			cout << a[i];
		}
	}

	cout << endl << kaisuu << endl;
}
