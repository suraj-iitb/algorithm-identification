#include <stdio.h>

void Insertation_Sort(int a[], int m) {

	int i, j, v;

	for (i = 1; i < m; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int main(void) {
	int s[100000], t[50000];
	int i, j;
	int n, m, count = 0, mark = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &t[i]);
	}

	Insertation_Sort(t, m);

	for (i = 0; i < m; i++) {
		for (j = mark; j < n; j++) {
			if (t[i] == s[j]) {
				mark = j;
				count++;
				break;
			}
			if (t[i] < s[j]) {
				mark = j;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
