#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		
		printf("%d", a[i]);
	}
	printf("\n");
}

int insertion_sort(int a[], int n)
{
	int i = 0, j = 0;
	int v = 0;
	
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = v;
		
		display(a, n);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	
	int a[100];
	int i = 0;
	int n = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}	
	
	display(a, n);
	
	insertion_sort(a, n);

	return 0;
}
