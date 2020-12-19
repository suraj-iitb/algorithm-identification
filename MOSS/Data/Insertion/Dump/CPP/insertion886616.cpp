#include <iostream>

using namespace std;

int main() {
	int n;
	int suretu[100];
	int key;
	int i;

	cin >> n;

	for (int j = 0; j < n; j++) {
		cin >> suretu[j];
	}

	for (int j = 1; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (k != 0) {
				cout << " " << flush;
			}
			cout << suretu[k] << flush;
		}
		cout << endl;
		key = suretu[j];
		i = j - 1;
		while (i >= 0 && suretu[i] > key) {
			suretu[i+1] = suretu[i];
			i--;
		}
		suretu[i+1] = key;
	}

	for (int k = 0; k < n; k++) {
		if (k != 0) {
			cout << " " << flush;
		}
		cout << suretu[k] << flush;
	}
	cout << endl;

	return 0;
}
