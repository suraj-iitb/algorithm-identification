#include <iostream>
using namespace std;

int bubbleSort(int N, int* A) {
	bool flag = true;
	int ret = 0;
	while (flag) {
		flag = false;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = true;
				ret++;
			}
		}
	}
	return ret;
}

int main()
{
	int N = 0, c = 0;
	int A[100] = {};
	cin >> N;
	while (c < N) {
		cin >> A[c];
		c++;
	}
	int swapCount = bubbleSort(N, A);
	for (int i = 0; i < N; i++) {
		if(i == 0) cout << A[i];
		else cout << " " << A[i];
	}
	cout << endl << swapCount << endl;
    return 0;
}


