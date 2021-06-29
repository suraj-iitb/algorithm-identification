#include <stdio.h>

int main(void)
{
	int s[100000], t[50000];
	int c = 0;
	int n, q;
	int i;

	int binary_search(int s[], int s_min, int s_max, int target);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
	}
	
	for (i = 0; i < q; i++) {
		if (binary_search(s, 0, n, t[i])) {
			c++;
		}
	}

	printf("%d\n", c);

	return 0;
}

int binary_search(int s[], int s_min, int s_max, int target) {
	int s_med;

	while (s_min < s_max) {
		s_med = (s_max + s_min) / 2;
		if (target == s[s_med]) {
			return 1;
		}
		if (target > s[s_med]) {
			s_min = s_med + 1;
		}
		else if (target < s[s_med]) {
			s_max = s_med;
		}
	}
	return 0;
}
