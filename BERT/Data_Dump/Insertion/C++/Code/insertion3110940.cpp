#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n,v;
	cin >> n;
	int A[100];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[n - 1] << endl;

	int j;
	for (int i = 1; i < n; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		//結果表示
		for (int i = 0; i < n-1; i++) {
			cout << A[i] << " ";
		}
		cout << A[n-1] << endl;
	}

	return 0;
}
