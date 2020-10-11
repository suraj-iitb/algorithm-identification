#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int n;
	int C[10001];
	int i;
	int m, l;
	m = 10001;
	int *pC = C;
	scanf("%d", &n);
	while (m--) {
		*(pC++) = 0;
	}

	for (i = 0; i < n; ++i) {
		scanf("%d", &m);
		++C[m];
	}

	m = 10001;
	pC = C;
	while (m--) {
		n = *(pC++);
		if (n-- != 0) {
			l = 10000 - m;
			printf("%d", l);
			while (n--) {
				printf(" %d", l);
			}
			break;
		}
	}
	while (m--) {
		n = *(pC++);
		if (n != 0) {
			l = 10000 - m;
			while (n--) {
				printf(" %d", l);
			}
		}
	}
	printf("\n");


	return 0;
}
