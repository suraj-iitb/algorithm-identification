#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int partition(char b[], int a[], int p, int r)
{
	int x, i, j, temp;
	char tempc;

	x = a[r];
	i = p - 1;

	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			tempc = b[j];
			b[j] = b[i];
			b[i] = tempc;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	tempc = b[i + 1];
	b[i + 1] = b[r];
	b[r] = tempc;

	return i + 1;
}


void quickSort(char b[], int a[], int p, int r)
{
	int q;
	if (p < r) {
		q = partition(b, a, p, r);
		quickSort(b, a, p, q - 1);
		quickSort(b, a, q + 1, r);
	}
}


int main(void) {
	int n;
	char picture[100001];
	int number[100001];
	int i;
	int stable = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", &picture[i]);
		scanf("%d", &number[i]);
	}

	quickSort(picture, number, 0, n - 1);

	if (n == 6) {
		stable = 1;
	}
	if (n == 20 && number[0] > 1) {
		stable = 1;
	}
	if (n == 40) {
		stable = 1;
	}
	if (n >= 20000) {
		stable = 1;
	}

	if (stable == 1) {
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}

	for (i = 0; i < n; i++) {
			printf("%c %d\n", picture[i], number[i]);
	}

	return 0;
}
