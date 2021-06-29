#include<iostream>
#include<cstdio>
#define N 100
using namespace std;

void bubbleSort(int n, int A[]) {
	bool flag = 1;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int i = n - 1; i > 0; i--) {
			int j = i - 1;
			if (A[i] < A[j]) {
				int t = A[i];
				A[i] = A[j];
				A[j] = t;
				flag = 1;
				count++;
			}
			/*cout << "[" << i << "]" << " ";
			for (int k = 0; k < n; k++) {
				cout << A[k] << " ";
			}
			cout << endl;*/
		}
	}
	for (int i = 0; i < n; i++) {
	    if(i != n-1) cout << A[i] << " ";
	    else cout << A[i];
	}
	cout << endl << count << endl;
}

int main() {
	int n;
	int A[N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	bubbleSort(n, A);

}
