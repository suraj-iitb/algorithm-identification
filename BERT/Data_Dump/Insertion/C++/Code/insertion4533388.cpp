//#include<iostream>
//using namespace std;
//
//int main() {
//
//	int n;
//	int j;
//	cin >> n;
//	int a[105];
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (i != n - 1) cout << a[i] << " ";
//		if (i == n - 1)cout << a[i] << endl;
//	}
//	for (int i = 1; i < n; i++) {
//
//		int v = a[i];
//
//		j = i - 1;
//		while (j >= 0 && a[j] > v) {
//			a[j + 1] = a[j];
//			j--;
//		}
//		a[j + 1] = v;
//		for (int i = 0; i < n; i++) {
//			if (i != n - 1) cout << a[i] << " ";
//			if (i == n - 1)cout << a[i] << endl;
//		}
//
//	}
//
//
//}

#include<iostream>

using namespace std;
int main() {
	int n,v;
	int A[105];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1)cout << A[i] << endl;
		else cout << A[i] << " ";
	}


	for (int i = 1; i <= n - 1; i++) {
		v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (int i = 0; i < n; i++) {
			if (i == n - 1)cout << A[i] << endl;
			else cout << A[i] << " ";
		}

	}
	return 0;
}
