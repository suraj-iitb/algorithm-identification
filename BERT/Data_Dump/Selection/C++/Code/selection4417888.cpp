#include<iostream>
using namespace std;

int selectionSort(int A[],int N) {
	int count = 0;
	int flag;
	for (int i = 0; i < N; i++) {
		int minj = i;
		flag = 0;
		for (int j = i; j < N; j++) {
			if (A[minj] > A[j]) {
				minj = j;
				flag = 1;
			}
		}
		if (flag==1) {
			int tmp;
			tmp = A[minj];
			A[minj] = A[i];
			A[i] = tmp;
			count += 1;

		}
	}
	for (int i = 0; i < N-1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N - 1];
	cout<<endl;
	return count;
}

int main() {
	int N, A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << selectionSort(A, N) << endl;
}
