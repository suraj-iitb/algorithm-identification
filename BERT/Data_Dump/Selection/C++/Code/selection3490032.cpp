#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>

void trace(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n");
}

int selectSort(int a[], int n) {
	int min ,num=0,tag;//num记录交换次数
	for (int i = 0; i < n; i++) {
		int k = -1;//记录最小值的位置
		tag = 0;//标记a[i]是否是最小值，决定是否发生交换
		min = a[i];//记录最小值，默认是当前的a[i]
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				k = j;
				tag = 1;
			}
		}
		if (tag) {//如果a[i]不是min，则交换之
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
		//trace(a,n);
		num++;
	}
	}
	return num;
}

int main() {
	int n, i, j;
	int a[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

		
		int m = selectSort(a, n);
		trace(a, n);
		printf("%d\n", m);
	

	return 0;
}
