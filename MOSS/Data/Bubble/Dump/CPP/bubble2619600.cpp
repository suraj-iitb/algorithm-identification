#include <iostream>
using namespace std;

int main()
{
	int n = 0, flag = 1, a[100] = { 0 }, temp = 0, k = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	while (flag) {
		flag = 0;
		for (int j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				k++;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;

	cout << k << endl;
		
	return 0;
}
