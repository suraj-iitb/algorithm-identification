#include <stdio.h>

int main ()
{
	int n, a[101], i, minj, j, tmp, count;
	
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
	}
	
	count = 0;
	
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (a[i] > a[minj]) {
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
		}
	}
	
	for (i = 0; i < n; i++) {
		if(i) {
			printf (" ");
		}
		printf ("%d", a[i]);
		}
		printf ("\n%d\n", count);
	return 0;
}

