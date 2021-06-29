#include <iostream>
using namespace std;


void insertionSort(int a[], int n) {
	for (int i = 0;i < n;i++) {
		int v = a[i], j = i - 1;
		
		while (j >= 0 && v < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		
		a[j + 1] = v;
		
		for (int j = 0;j < n;j++) {
			if (j != n - 1) {
				cout << a[j] << " ";
			}
			else {
				cout << a[j] << endl;
			}
		}
	}
}


int main()
{
	int n, a[100];
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	insertionSort(a, n);

    return 0;
}

