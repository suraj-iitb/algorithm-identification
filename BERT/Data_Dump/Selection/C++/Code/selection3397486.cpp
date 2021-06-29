#include <iostream>
using namespace std;

int selectionSort(int N, int* A) {
	int minj = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		swap(A[i], A[minj]);
		if(i != minj) ret++;
	}
	return ret;
}

int main()
{
	int N = 0;
	int A[100] = {};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int selectNum = selectionSort(N, A);
	for (int j = 0; j < N; j++) {
		if (j == 0) cout << A[j];
		else cout << " " << A[j];
	}
	cout << endl << selectNum << endl;
    return 0;
}
