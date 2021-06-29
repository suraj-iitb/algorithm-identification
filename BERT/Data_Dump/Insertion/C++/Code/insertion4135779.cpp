#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int numbers[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> numbers[i];

	for (int k = 0; k < n; k ++) if (k != n - 1)cout << numbers[k] << " "; else cout << numbers[k];
	cout << endl;
	for (int i = 1; i < n; i ++) {
		int v = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > v) {
			numbers[j + 1] = numbers[j];
			j --;
		}
		numbers[j + 1] = v;

		for (int k = 0; k < n; k ++) if (k != n - 1)cout << numbers[k] << " "; else cout << numbers[k];
		cout << endl;
	}


	return 0;
}
