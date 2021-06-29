#include <iostream>

#define MAX_N 100

using namespace std;

int n, steps = 0;
int numbers[MAX_N];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> numbers[i];

	for (int i = 0; i < n - 1; i ++) {
		int minIndex = i;
		for (int j = i; j < n; j ++) {
			if (numbers[j] < numbers[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(numbers[minIndex], numbers[i]);
			steps ++;
		}
	}

	for (int i = 0; i < n; i ++) if (i == 0) cout << numbers[i]; else cout << " " << numbers[i];
	cout << endl << steps << endl;

	return 0;
}
