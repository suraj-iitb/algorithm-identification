#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int N, A[101];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int temp;
	int idx;
	for (int i = 0; i < N; i++) {
		temp = A[i];
		idx = 0;
		for (int j = 0; j < i; j++) {
			idx = j;
			if (A[j] > temp) {
				idx--;
				break;
			}
		}
		for (int l = idx+1; l <= i; l++) {
			int temp2 = A[l];
			A[l] = temp;
			temp = temp2;
		}
		for (int j = 0; j < N-1; j++) cout << A[j] << " ";
		cout << A[N-1]<< endl;
	}
	return 0;
}
