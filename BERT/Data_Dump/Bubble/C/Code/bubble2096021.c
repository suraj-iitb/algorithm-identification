#include <stdio.h>

//????????????.
void swap(int *x, int *y);

//??????????????????????????°?????????.
int bubbleSort(int *a, int n);

int main(void) {
	int i = 0;

	int n = 0;		//?????????????´???°.
	int a[100] = {};//??????.

	int ex = 0;		//???????????°.

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	ex = bubbleSort(a, n);

	for (i = 0; i < n; i++) {
		if (i != n - 1)
			printf("%d ", a[i]);
		else
			printf("%d\n%d\n", a[i], ex);
	}

	return 0;
}

void swap(int *x, int *y) {
	int tmp = 0;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int bubbleSort(int *a, int n) {
	int ex = 0;		//???????????°.
	int j = 0;
	int flag = 1;	//????????£??\????´?????????¨??????.

	while (flag) {
		flag = 0;
		for (j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
				flag = 1;
				ex++;
			}
		}
	}

	return ex;
}