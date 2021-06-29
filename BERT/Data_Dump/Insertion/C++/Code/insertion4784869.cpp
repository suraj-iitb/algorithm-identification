#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	int N;
	cin >> N;
	int *A = new int[N];
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 1; i < N; i++) {
		for (int i = 0; i < N - 1; i++) cout << A[i] << ' ';
		cout << A[N - 1] << '\n';
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}

	for (int i = 0; i < N - 1; i++) cout << A[i] << ' ';
	cout << A[N - 1] << '\n';


	return 0;
}

//made by myself
