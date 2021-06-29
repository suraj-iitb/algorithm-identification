#include <stdio.h>

int main() {
	int n, c;
	scanf("%d", &n);

	int arr[n];
	for (int i=0; i<n;i++) {
		scanf("%d", &arr[i]);
	}

	c = 0;
	for (int i=0; i<n; i++) {
		for (int j=n-1; j>i;j--) {
			if (arr[j] < arr[j-1]) {
				c++;
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}

	printf("%d", arr[0]);
	for (int i=1; i<n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n%d\n", c);
}

