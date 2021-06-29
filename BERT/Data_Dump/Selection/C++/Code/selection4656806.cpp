#include<iostream>
using namespace std;

void out(int*A, int N) {
	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout << " " << A[i];
	}
	cout << endl;
}

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void selectsort(int*A, int N) {
	int head = 0;
	int count = 0;
	while (head < N) {
		int minj = head;
		for (int j = head; j < N; j++) {
			if (A[minj] > A[j])
				minj = j;
		}
		if (A[head]>A[minj]){
			swap(A[head], A[minj]);
			count++;
		}	
		head++;
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
	selectsort(A, N);
}
