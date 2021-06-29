#define NOT_FOUND 20000

#include <stdio.h>

//????????????????????£?¨?.
int linearSearch(int key, int *t, int n);

int main(void) {
	int s[10001] = {};
	int t[501] = {};
	int n = 0;
	int q = 0;
	int k = 0;				//?????´????????°.
	int i = 0;
	int j = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &t[i]);

	for (i = 0; i < q; i++) {
		if (linearSearch(t[i], s, n) != NOT_FOUND)
			k++;
	}

	printf("%d\n", k);

	return 0;
}

//key?????¢?´¢.
int linearSearch(int key, int *s, int n) {
	int i = 0;

	s[n] = key;

	while (s[i] != key) {
		i++;
	}

	if (i == n)
		return NOT_FOUND;

	return i;
}
