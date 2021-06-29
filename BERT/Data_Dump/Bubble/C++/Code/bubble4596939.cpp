#include <iostream>

using namespace std;

void func(){
	int A[100];
	int N, temp;
	int count = 0;
	bool flag = 1;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int j =0; flag; j++) {
		flag = 0;

		for (int i = N - 1; i >= j + 1; i--) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i - 1]);
				flag = 1;
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++){
if(i) cout << " ";
		cout << A[i];
}
	cout << endl;
	cout << count << endl;
}

int main() {
	func();
	return 0;
}
