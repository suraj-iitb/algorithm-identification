# include <stdio.h>
void trace(int A[], int N);
void insertionSort(int A[], int N);


int main() {
	int N, i;
	int A[100];

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);

	trace(A, N);
	insertionSort(A, N);

	return 0;
}


/*按顺序输出数组元素*/
void trace(int A[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

/*插入排序（0起点数组）*/
void insertionSort(int A[], int N) {
	//传入数组是地址传递
	int j, i, v;
	for (int i = 1; i < N; i++) {
		//从1开始判断
		//保存当前值
		v = A[i];
		j = i - 1;//判断的起始值，倒着判断
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;//将v保存到A[j + 1]
		//输出
		trace(A, N);
	}
}
