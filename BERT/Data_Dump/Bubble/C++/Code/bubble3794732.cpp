#include <cstdio>
//trace函数见前面, 按顺序输出数组元素
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
void bubbleSort(int a[], int n) {
	int swapCount = 0;
	for (int i = n - 1; i > 0; i--) {
		int flag = 1; 
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = 0; swapCount++;
			}
		}
		//trace(a, n); 
		if (flag) break; //当数组不存在顺序相反的相邻元素提前退出 
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
    bubbleSort(a, N);
    return 0;
}
