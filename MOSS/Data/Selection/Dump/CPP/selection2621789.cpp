#include <iostream>
using namespace std;

int main()
{
	int n = 0, a[100] = { 0 }, minj = 0, temp = 0, k = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++){

		minj = i;

		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}

		if (minj > i) {
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			k++;
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;

	cout << k << endl;
		
	return 0;
}
