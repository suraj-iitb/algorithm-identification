#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int swap1(int seisu[], int cou, int n)
{
	int irekae;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = n - 1; 0 < j; j--) {
			if (seisu[j] < seisu[j - 1]) {
				irekae = seisu[j];
				seisu[j] = seisu[j - 1];
				seisu[j - 1] = irekae;
				cou++;
			}
		}
	}
	return cou;

}



int main(void)
{
	int i = 0, j = 0, n = 0, count = 0;
	int seisu[250];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &seisu[i]);
	}


	count = swap1(seisu, count, n);


	for (i = 0; i < n; i++) {

		printf("%d", seisu[i]);
		if (i != (n - 1))
			putchar(' ');
	}

	putchar('\n');

	printf("%d\n", count);

	return 0;

}
