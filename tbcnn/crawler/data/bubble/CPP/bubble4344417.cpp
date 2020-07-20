#include<bits/stdc++.h>
using namespace std;


int A[100];

int bubbleSort(int A[], int n) {
	int cnt = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = n - 1; i >= 1; i--) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i - 1]);
				cnt++;
				flag = true;
			}
		}
	}
	return cnt;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> A[i];

	int cnt = bubbleSort(A, n);

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << A[i] << endl;
			break;
		}
		cout << A[i] << " ";
	}

	cout << cnt << endl;
		
	return 0;

}
