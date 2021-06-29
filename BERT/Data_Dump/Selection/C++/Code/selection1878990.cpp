#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int N, A[100], work, minj, cou = 0;
	bool flag = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			work = A[i];
			A[i] = A[minj];
			A[minj] = work; 
			cou++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1)  cout << " ";
		else cout << endl;
	}
	cout << cou << endl;
}
