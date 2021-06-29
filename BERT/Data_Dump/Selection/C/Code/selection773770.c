#include <stdio.h>
int main(void) {
	int data[100], n, i, j, mini, swap_times, swap_flag, tmp;
	const char *fmt = "%d";

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", data+i);
	}
	swap_times = 0;
	for (i = 0; i < n; i++) {
		mini = i;
		swap_flag = 0;
		for (j = i; j < n; j++) {
			if (data[j] < data[mini]) {
				mini = j;
				swap_flag = 1;
			}
		}
		tmp = data[i];
		data[i] = data[mini];
		data[mini] = tmp;
		swap_times += swap_flag;
	}
	for (i = 0; i < n; i++) {
		printf(fmt, data[i]);
		fmt = " %d";
	}
	printf("\n%d\n", swap_times);
	return 0;
}
