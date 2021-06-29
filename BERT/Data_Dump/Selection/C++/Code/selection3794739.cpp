#include <cstdio>
//按顺序输出数组元素
void trace(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void selectionSort(int a[], int n) {
	int minj, swapCount = 0;
	for (int i = 0; i < n; i++) {
		minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) minj = j;
		}
		if (i != minj) {
			swap(a[i], a[minj]);
			swapCount++;
		}
	}
	trace(a, n);
	printf("%d\n", swapCount);
} 

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
    	scanf("%d", &a[i]);
	}
    selectionSort(a, N);
    return 0;
}
