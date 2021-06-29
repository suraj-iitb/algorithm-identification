#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *a, int n);
void swapInt(int *a, int *b);

int main() {
	int n;
	int *a;
	int i,cnt;
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	cnt = bubbleSort(a, n);

	for (i = 0; i < n; i++) {
		printf("%d", *(a + i));
		if (i != n - 1)printf(" ");
	}
	printf("\n");
	printf("%d\n",cnt);
	return 0;
}

int bubbleSort(int *a, int n) {
	int i,flag=1;
	int swapCount = 0;
	while (flag) {
		flag = 0;
		for (i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				swapInt(&a[i], &a[i-1]);
				flag = 1;
				swapCount++;
			}
		}
	}
	return swapCount;
}

void swapInt(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
