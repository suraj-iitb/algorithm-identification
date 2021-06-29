#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bubbleSort(int a[], int n)
{
	bool flag = true;
	int count = 0;
	for (int i = 0; i < n - 1 && flag; i++) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				flag = true;
				count++;
			}
		}
	}
	return count;
}


int main(void)
{
	int N;
	cin >> N;

	int A[100];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int count;
	count = bubbleSort(A, N);

	for (int k = 0; k < N; k++) {
		if (k > 0) cout << ' ';
		cout << A[k];
	}
	cout << '\n' << count << endl;

	return 0;
}
