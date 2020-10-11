#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int selection_sort(int a[], int n)
{
	int i, j;
	int minj;
	int sw = 0;
	
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[minj] > a[j]) {
				minj = j;
			}
		}
		
		if (i != minj) {
			swap(&a[i], &a[minj]);
			sw++;
		}
	}
	
	for (i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	
	return 0;
}

int main(int argc, char *argv[]) {
	
	int n;
	int i;
	int a[100];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	selection_sort(a, n);
	
	return 0;
}
