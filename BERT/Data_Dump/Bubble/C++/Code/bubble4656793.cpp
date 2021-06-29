#include<iostream>
using namespace std;

void out(int*A, int N) {
	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout << " " << A[i];
	}
	cout << endl;
}

void bubblesort(int*A, int N) {
	int temp;
	int count = 0;
	int flag = 1;
	while (flag){
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				count++;
				flag = 1;
			}
		}
	}
	out(A, N);
	cout << count << endl;
}

int main() {
	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	bubblesort(A, N);
}

