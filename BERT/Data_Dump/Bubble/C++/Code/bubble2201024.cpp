#include<iostream>
using namespace std;

int main()
{
	int A[100], N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	bool flag = true;
	int count = 0;
	int end = 0;
	while (flag) {
		flag = false;
		for (int i = N - 1; i > end; i--) {
			if (A[i-1] > A[i]) {
				swap(A[i - 1], A[i]);
				count++;
				flag = true;
			}
		}
		end++;
	}

	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout << ' ' << A[i];
	}
	cout << endl << count << endl;
}
