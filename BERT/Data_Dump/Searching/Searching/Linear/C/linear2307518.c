#include <stdio.h>

#define N 10000
#define Q 500

int linearSearch(int *A, int key, int length) {
	int i = 0;

	A[length] = key;

	while (A[i] != key) {
		i++;
	}

	if (i == length) return 0;
	return 1;
}

int main() {
	int n,q,i;
	int num = 0;
	int s[N], t[Q];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &s[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++) scanf("%d", &t[i]);

	for (i = 0; i < q; i++) num += linearSearch(s, t[i], n);

	printf("%d\n", num);

	return 0;
}
