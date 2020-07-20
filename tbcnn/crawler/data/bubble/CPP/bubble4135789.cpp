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

	bool flag = true;
	int i = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j > i; j --) {
			if (numbers[j] < numbers[j - 1]) {
				swap(numbers[j], numbers[j - 1]);
				flag = true;
				steps ++;
			}
		}
	}

	for (int i = 0; i < n; i ++) if (i == 0) cout << numbers[i]; else cout << " " << numbers[i];
	cout << endl << steps << endl;

	return 0;
}
