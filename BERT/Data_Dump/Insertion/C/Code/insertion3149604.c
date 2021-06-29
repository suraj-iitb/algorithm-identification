#include <stdio.h>
#define MAX_INDEX 1000


void print_a(int a[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
}

void insertionSort(int a[],int  n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		print_a(a, n);
	}
}


int main() {
	int a[MAX_INDEX], n;
	scanf("%d", &n);
	int i = 0;
	int ch;
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	print_a(a, n);
	insertionSort(a, n);

}
