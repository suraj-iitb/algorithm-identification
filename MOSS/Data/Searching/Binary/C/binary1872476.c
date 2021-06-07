#include <stdio.h>
#include <stdlib.h>

int binary_search(long long *list, int s_ind, int e_ind, long long search_val)
{
	if (s_ind >= e_ind) {
		return list[s_ind] == search_val ? s_ind : -1;
	}

	int mid_ind = s_ind + ((e_ind - s_ind) / 2);

	if (list[mid_ind] < search_val) {
		return binary_search(list, mid_ind+1, e_ind, search_val);
	}
	else if (list[mid_ind] > search_val) {
		return binary_search(list, s_ind, mid_ind-1, search_val);
	}
	else {
		return mid_ind;
	}
}

int main(int argc, char *argv[])
{
	int i, n, q, cnt;
	long long S[100000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		long long num;
		scanf("%lld", &num);
		S[i] = num;
	}

	cnt = 0;
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		long long num;
		scanf("%lld", &num);
		if (binary_search(S, 0, n - 1, num) > -1) {
			++cnt;
		}
	}

	printf("%d\n", cnt);
	return 0;
}
