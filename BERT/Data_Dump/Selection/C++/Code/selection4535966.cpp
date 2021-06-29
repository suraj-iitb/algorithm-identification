//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//int main() {
//
//	int n;
//
//	cin >> n;
//	int a[105];
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	int sum = 0;
//
//	for (int i = 0; i < n; i++) {
//		int minj = i;
//		for (int j = i; j < n; j++) {
//			if (a[j] < a[minj]) {
//				minj = j;
//			}
//		}
//		if (minj != i) {
//			int tmp = a[i];
//			a[i] = a[minj];
//			a[minj] = tmp;
//			sum++;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (i != n - 1)cout << a[i] << " ";
//		if (i == n - 1)cout << a[i] << endl;
//	}
//	cout << sum << endl;
//}
//


//round 2

#include<iostream>
using namespace std;


int selectionSort(int A[], int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
				cnt++;
		};
	}

	return cnt;
}

int main() {
	int n;

	cin >> n;
	int A[105];

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int ans = selectionSort(A, n);

	for (int i = 0; i < n; i++) {
		if (i == n - 1)cout << A[i] << endl;
		else cout << A[i] << " ";
	}
	cout << ans << endl;

}
