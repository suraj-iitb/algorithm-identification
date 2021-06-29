#include <iostream>

using namespace std;

int main(void) {
	int N;

	cin >> N;

	int *ary = new int[N];
	
	int i, x;
	for (i = 0; i < N; i++) {
		cin >> ary[i];
	}
	for (x = 0; x < N - 1; x++) {
		cout << ary[x] << " ";
	}
	cout << ary[N - 1] << endl;


	for (i = 1; i < N; i++) {
		int v = ary[i];
		int j = i - 1;
		while ((j >= 0) && (ary[j] > v)) {
			ary[j + 1] = ary[j];
			j--;
		}
		ary[j + 1] = v;

		for (x = 0; x < N - 1; x++) {
			cout << ary[x] << " ";
		}
		cout << ary[N - 1] << endl;
	}

	delete[] ary;

	int ch;
	cin >> ch;

	return 0;
}
