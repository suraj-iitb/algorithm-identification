#include <stdio.h>

int main(void) {
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;	//?????????????????°.
	int v = 0;

	int card[100] = {};	//??????????????????.

	//????????????????????????.
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &card[i]);

	for (i = 1; i < n; i++) {
		
		//???????????????.
		for (k = 0; k < n; k++) {
			if (k == n - 1)
				printf("%d\n", card[k]);
			else
				printf("%d ", card[k]);
		}

		v = card[i];
		j = i - 1;
		while (j >= 0 && card[j] > v) {
			card[j+1] = card[j];
			j--;
		}
		card[j+1] = v;
	}

	//???????????????.
	for (k = 0; k < n; k++) {
		if (k == n - 1)
			printf("%d\n", card[k]);
		else
			printf("%d ", card[k]);
	}

	return 0;
}