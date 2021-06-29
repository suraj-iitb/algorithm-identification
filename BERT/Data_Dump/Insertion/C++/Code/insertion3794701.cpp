#include <cstdio>
//按顺序输出数组元素
void trace(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}
void insertionSort(int a[], int n) {
	int temp, j;
	for (int i = 1; i < n; i++) {
		temp = a[i]; 
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		trace(a, n);
	}
}

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
    	scanf("%d", &a[i]);
	}
	trace(a, N);
    insertionSort(a, N);
    return 0;
}
