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
//	int i = 0;
//	while (i <= n - 1) {
//		for (int j = n - 1; j > i ; j--) {
//			if (a[j] < a[j - 1]) {
//				int tmp = a[j];
//				a[j] = a[j-1];
//				a[j - 1] = tmp;
//				sum++;
//			}
//		}
//
//		i++;
//	}
//
//	for (int i = 0; i < n; i++) {
//		if(i!=n-1)cout << a[i] << " ";
//		if (i == n - 1)cout << a[i] << endl;
//	}
//	cout << sum << endl;
//}
//


//Bubble sort
#include<iostream>
using namespace std;

int bublleSort(int A[], int N) {
	int flag = 1;
	int cnt = 0;

	while (flag) {
		flag = 0;
		for (int j = N - 1; j >= 1; j--) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				cnt++;
			}

		}
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

	int ans = bublleSort(A, n);

	for (int i = 0; i < n; i++) {
		if (i == n - 1)cout << A[i] << endl;
		else cout << A[i] << " ";
	}
	cout << ans << endl;

}
