#include "stdio.h"
#include <iostream> 

using namespace std;
static int MAX_N = 100;

void trace(int* num, int n) {
	for(int i = 0; i < n - 1; i ++) {
		printf("%d ", num[i]);
	}
	printf("%d\n", num[n - 1]);
}

void insertionSort(int n, int* num) {
	for(int i = 1; i < n; i ++) {
		int key = num[i];
		int j = i - 1;
		while(num[j] > key & j >= 0) {
			num[j + 1] = num[j];
			j --;
		}
		num[j + 1] = key;
		trace(num, n);		
	}
}

int main() {
	int n, num[MAX_N];
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &num[i]);
	}
	trace(num, n);
	insertionSort(n, num);
}
