#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int suretu[100];
	int counter = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> suretu[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > i; j--) {
			if (suretu[j] < suretu[j-1]) {
				swap(suretu[j], suretu[j-1]);
				counter++;
			}
		}
	}

	cout << suretu[0] << flush;

	for (int i = 1; i < n; i++) {
		cout << ' ' << suretu[i];
	}

	cout << endl << counter << endl;

	return 0;
}
