#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int array[100];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	int count = 0;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (array[j] < array[j - 1]) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				count++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d%c", array[i], i != n - 1 ? ' ' : '\n');
	}
	printf("%d\n", count);

	return 0;
}
