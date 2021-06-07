#include<stdio.h>
int main() {
	int n, q, i, j,sv=0, ct = 0, at = 0;
	int S[10000];
	int T[10000];
	int save[10000];

	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i<q; i++) {
		scanf("%d", &T[i]);
	}


	for (i = 0; i<n; i++) {
		for (j = 0; j<q; j++) {
			if (S[i] == T[j]) {
				save[sv] = T[j];
				ct++;
				sv++;
				break;
			}
		}
	}
	at = ct;

	for (i = 0; i<ct; i++) {
		if (save[i] < 0)continue;
		for (j = i + 1; j < ct; j++) {
			if (save[i] == save[j]) {
				save[j] = -1;
				at--;
			}
		}
	}
	/*for (i = 0; i < ct; i++) { printf("%d\n", save[i]); }*/

	printf("%d\n", at);
	return 0;
}


