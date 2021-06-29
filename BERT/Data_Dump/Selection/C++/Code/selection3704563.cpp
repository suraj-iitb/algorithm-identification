#include <bits/stdc++.h>
using namespace std;

void trace(int a[], int N) {
	for (int i = 0; i < N; i++) {
		printf("%d", a[i]);
		if (i < N - 1) printf(" ");
	}
	printf("\n");
	return;
}

int selectionsort(int a[], int N) {
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (a[j] < a[minj]) minj = j;
		}
		int temp = a[i]; a[i] = a[minj]; a[minj] = temp;
		if (i != minj) cnt++;
	}
	return cnt;
}

int main() {
	int N; scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = selectionsort(a, N);
	trace(a, N);
	printf("%d\n", cnt);
	return 0;
}
