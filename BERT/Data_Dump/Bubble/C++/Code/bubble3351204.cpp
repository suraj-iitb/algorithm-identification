#include <iostream>
#include <string>

using namespace std;

int bubbleSort(int A[], int N);

int main() {
	int N;
	int count = 0;
	cin >> N;

	int A[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}

	count = bubbleSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i < N - 1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	}
	cout << count << endl;
}

int bubbleSort(int A[], int N) {
	int flag = 1;
	int count = 0;

	while (flag) {
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				count++;
			}
		}
	}
	return count;
}
