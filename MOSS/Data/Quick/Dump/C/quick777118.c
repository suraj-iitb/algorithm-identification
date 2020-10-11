#include <stdio.h>
#include <string.h>
#define MAX_N 100000

struct card_t {
	char s;
	int n;
	int idx;
};
typedef struct card_t Card;

int patition(Card a[MAX_N], int p, int r) {
	int x, i, j, t, s;
	char c;

	x = a[r].n;
	i = p - 1;
	for (j = p; j < r; j++) {
		if (a[j].n <= x) {
			i += 1;
			c = a[i].s;
			t = a[i].n;
			s = a[i].idx;
			a[i].s = a[j].s;
			a[i].n = a[j].n;
			a[i].idx = a[j].idx;
			a[j].s = c;
			a[j].n = t;
			a[j].idx = s;
		}
	}
	c = a[i+1].s;
	t = a[i+1].n;
	s = a[i+1].idx;
	a[i+1].s = a[r].s;
	a[i+1].n = a[r].n;
	a[i+1].idx = a[r].idx;
	a[r].s = c;
	a[r].n = t;
	a[r].idx = s;
	return i + 1;
}

void quick_sort(Card a[MAX_N], int p, int r) {
	int q;

	if (p < r) {
		q = patition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

int main(void) {
	Card in[MAX_N];
	int n, i;
	const char *stable;

	scanf("%d ", &n);
	for (i = 0; i < n; i++) {
		scanf("%c %d ", &in[i].s, &in[i].n);
		in[i].idx = i;
	}
	quick_sort(in, 0, n-1);

	stable = "Stable";
	for (i = 0; i < n-1; i++) {
		if (in[i].n == in[i+1].n && in[i].idx > in[i+1].idx) {
			stable = "Not stable";
			break;
		}
	}
	puts(stable);

	for (i = 0; i < n; i++) {
		printf("%c %d\n", in[i].s, in[i].n);
	}
	return 0;
}
