# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define A_MAX 1000

void dispa(int a[],int n);
void insertisionSort(int a[], int n);

int main (void) {

	int n;
	int i;

	int a[A_MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	dispa(a, n);

	insertisionSort(a, n);
	
	return 0;
}

void insertisionSort(int a[], int n) {
	
	int i;
	int j;
	int v;

	for (i = 1; i <= n - 1; i++) {
		v = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		dispa(a, n);
	}
}

void dispa(int a[], int n) {

	int i;

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 != n) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}

}
