#include <stdio.h>
#include <stdlib.h>

int sort(void *a, void *b) {
	return *(int *)a - *(int *)b;
}


int search(int s[], int x1, int x2, int v) {
	int c = (x2 - x1) >> 1;
	int x = x1 + c;
	if (c == 0) {
		return (s[x1] == v) || (s[x2] == v);
	} 
	if (s[x] > v) {
		return search(s, x1, x, v);
	} else if (s[x] < v) {
		return search(s, x, x2, v);
	}
	return 1;
}

int main(void) {
	int S[100000];
	int n, q;
	int v, c = 0;
	int i;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &v);
		S[i] = v;
	}
	
	qsort(S, n, sizeof(S[0]), sort);
	
	scanf("%d", &q);
	
	++q;
	while (--q) {
		scanf("%d", &v);
		if (search(S, 0, n - 1, v)) {
			++c;
		}
	}
	
	printf("%d\n", c);
	
	return 0;	
}
