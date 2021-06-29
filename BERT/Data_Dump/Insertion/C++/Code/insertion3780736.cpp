#include <iostream>

using namespace std;

int main() {
	int data[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> data[i];
	for (int i = 0; i < n; i++) {
		cout << data[i];
		if (i == (n - 1)) cout << endl;
		else cout << " ";
	}
	for (int i = 1; i < n; i++) {
		int key = data[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (data[j] >= key) {
				data[j + 1] = data[j];
			}
			else break;
		}

		data[j + 1] = key;

		for (int j = 0; j < n; j++) {
			cout << data[j];
			if (j == (n - 1)) cout << endl;
			else cout << " ";
		}
	}


	return 0;
}
