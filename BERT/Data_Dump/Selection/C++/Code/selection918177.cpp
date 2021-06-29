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
		int min = i;
		for (int j = i; j <= n - 1; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (i != min) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			count++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d%c", array[i], i != n - 1 ? ' ' : '\n');
	}
	printf("%d\n", count);

	return 0;
}
