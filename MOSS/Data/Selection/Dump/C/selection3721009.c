#include <stdio.h>

int main()
{
	int n, i, m, j;
	int array[100];
	int tmp;
	int count = 0;
	int min;
	int ichi = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &array[i]);
	}

	min = array[1];

	for (m = 1; m<n; m++) {
		min = array[m];
		for (j = m + 1; j <= n; j++) {
			if (min>array[j]) {
				min = array[j];//最小値探索
				ichi=j;//最小値の位置を記憶する
			}
		}
		if (array[m] != min) {
			tmp = array[m];
			array[m] = min;
			array[ichi] = tmp;
			count++;
		}
	}


	for (i = 1; i <= n; i++) {
		if (i != n) {
			printf("%d ", array[i]);
		}
		else {
			printf("%d\n", array[i]);
		}
	}
	printf("%d\n", count);
    return 0;
}

