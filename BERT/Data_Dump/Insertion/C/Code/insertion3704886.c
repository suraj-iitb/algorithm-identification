#include <stdio.h>

void swap(int *from,int*to);

int main(void) {
	int n, j, i,m;
	int array[100];

	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 1; i<=n; i++) {
		j = i;

		for (m = 0; m < n; m++) {
			
			if (m == n - 1){
			    printf("%d\n",array[m]);
			    
		}else {printf("%d ", array[m]);}
		}
		while (j>0 && array[j - 1]>array[j]) {
			swap(&array[j - 1], &array[j]);
			j--;
		}
	}

	return 0;
}

void swap(int *from, int*to) {
	int tmp = *from;
	*from = *to;
	*to = tmp;
}
