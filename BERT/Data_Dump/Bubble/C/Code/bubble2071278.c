#include <stdio.h>

int main() {
	int a[100] = { 0 };
	int number;
	int count;
	int i, j;
	int temp;

	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		scanf("%d", &a[i]);
	}

	count = 0;
	for (i = 0; i < number; i++) {
		for (j = number - 1; j > i; j--) {

    		if (a[j] < a[j - 1]) {
	    		temp = a[j];
		    	a[j] = a[j - 1];
		    	a[j - 1] = temp;
				count++;
		    }
		}
	}

	for (i = 0; i < number - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d", a[number - 1]);
	printf("\n%d\n", count);

	return 0;
}
