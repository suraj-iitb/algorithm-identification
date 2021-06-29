
#include <iostream>
using namespace std;

void insertionSort(int x[], int y) {

	int v;
	int j;
	for (int i = 1; i < y; i++) {
		v = x[i];
		j = i - 1;

		while (j >= 0 && x[j] > v)
		{
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = v;
		for (int k = 0; k < y; k++) {
			cout << x[k];
			if (k != y -1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}


int main()
{
	int a;
	cin >> a;
	int x[100];

	int i = 0;

	while (true)
	{
		cin >> x[i];
		i++;
		if (cin.eof()) { break; }
	}

	for (int k = 0; k < a; k++) {
		cout << x[k];
		if (k != a-1) {
			cout << " ";
		}
	}
	cout << endl;

	insertionSort(x, a);

	return 0;
}
