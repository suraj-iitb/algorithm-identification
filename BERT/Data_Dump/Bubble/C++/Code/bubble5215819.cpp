

#include<iostream>
using namespace std;

int bubbleSort(int A[], int N) {
	bool flag = 1;
	int count = 0;
	for (int i = 0; flag;i++) {
		flag = 0;
		
		for (int j = N - 1; j >= i+1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				count++;
			}
			
			
		}
	}
	return count;
}

int main() {
	int A[100], N, sw;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sw = bubbleSort(A , N);
	for (int i = 0; i < N; i++) {
		if (0<i)cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}

