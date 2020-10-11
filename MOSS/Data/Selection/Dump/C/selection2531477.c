#include <stdio.h>

int main(void) {
	int n;
	int a[100];
	int i, j;
	int minj;
	int count;
	int tmp;
	count = 0;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < n; i++){
		minj = i;
		for (j = i; j < n; j++){
			if (a[minj] > a[j]){
				minj = j;
			}
		}
		if (minj != i){
			tmp = a[minj];
			a[minj] = a[i];
			a[i] = tmp;
			count++;
		}
	}

	for (i = 0; i < n - 1; i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	printf("%d\n", count);
	
	return 0;
}
