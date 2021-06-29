#include "stdio.h"
#include <iostream>

using namespace std;

static int MAX_N = 100;

void trace(int n, int* num) {
	for(int i = 0; i < n - 1; i ++) {
		printf("%d ", num[i]);
	}
	printf("%d\n", num[n - 1]);
}

int  bobbleSort(int n, int* num) {
	int count = 0;
	for(int i = 0; i < n - 1; i ++) {
		for(int j = n - 1; j >= i; j --) {
			if(num[j] < num[j - 1]) {
				int temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
				count ++;
			}
		}
	}
	return count;
}

int main() {
	int n, num[MAX_N];
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &num[i]);
	}
	int count = bobbleSort(n, num);
	trace(n, num);
	printf("%d\n", count);
}
