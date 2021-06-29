#include<iostream>
#include <math.h>
using namespace std;


	int main() {
		int N, A[100];
		cin >> N;
		int a = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int flag = 1;
		while (flag == 1) {
			flag = 0;
			for (int j = N - 1; j >= 1; j--) {
				if (A[j - 1] > A[j]) {
					int tmp = A[j - 1];
					A[j - 1] = A[j];
					A[j] = tmp;
					flag = 1;
					a++;
				}
			}
		}
		for (int i = 0; i < N - 1; i++) {
			cout << A[i] << ' ';
		}
		cout << A[N-1] << endl;

		cout << a << endl;

		return 0;
	}

