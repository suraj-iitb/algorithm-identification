#include <stdio.h>
#include <math.h>

int main(void)
{
	int num = 0, numa, numb, key, i, j;
	int a[20000], b[600];

	scanf("%d", &numa);

	for (i = 0; i < numa; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &numb);
	
	for (i = 0; i < numb; i++) {
		scanf("%d", &b[i]);
	}

	for (j = 0; j < numb; j++) {
		i = 0;
		key = b[j];
		a[numa] = key;
		while (a[i] != key) {
			i++;
		}
		if (i != numa) {
			num++;
		}
	}

	printf("%d\n", num);
	
	return 0;
}
