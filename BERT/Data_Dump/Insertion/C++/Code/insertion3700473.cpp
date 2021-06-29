#include <stdio.h>

int ALDS1_1_A();
void printA(int* a, int n);

int main()
{
	return ALDS1_1_A();
}

void printA(int* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		i < n - 1 ? printf(" ") : printf("\n");
	}
}

int ALDS1_1_A() {
	int n, i, a[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int v, j;
	printA(a, n);
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		printA(a, n);
	}
	
	return 0;

}

