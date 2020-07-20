#include<iostream>
#include <cstdio>

using namespace std;

void bubblesort(int A[], int N) {

	int i, j, temp, count = 0;
	bool flag = 1;

	for (i = 0; flag; i++) {
		flag = 0;
		for (j = N-1; j >= i+1; j--){
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				count++;
				flag = 1;
			}
		}
	}

	for (i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
}

int main() {
	
	int N, i, A[100];

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];

	bubblesort(A, N);

	return 0;

}
