#include <iostream>
#include <algorithm>

using namespace std;

int selectionSort(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[index] > a[j]) {
				index = j;
			}
		}
		if (i != index) {
			count++;
			swap(a[i], a[index]);
		}
	}
	return count;
}

int main(void)
{
	int N;
	int A[100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int count = selectionSort(A, N);
	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout << ' ' << A[i];
	}
	cout << endl << count << endl;

	return 0;
}
