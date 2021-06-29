#include <stdio.h>

int main(void) {
	int S[10000], T[500], n, q, i, count;
	count = 0;

	scanf("%d",&n);
	for (i = 0;i < n;i++)
		scanf("%d", &S[i]);

	scanf("%d",&q);
	for (i = 0;i < q;i++) {
		scanf("%d", &T[i]);
		if (linearSearch(S, T[i], n) == 1) {
			count++;
		}
	}

	printf("%d\n", count);
	return 0;

}

int linearSearch(int s[], int key, int n) {
	int i = 0;
	s[n] = key;

	while (s[i] != key)
		i++;
	if (i == n)
		return 0;
	return 1;
}
