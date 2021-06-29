#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100;

int num[N];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int bubbleSort(int num[], int n) {//???????????? 
	int cnt = 0; //?????蔵?測???属 
	for (int i=0; i<n; ++i) {
		for (int j=n-1; j>i; --j) {
			if (num[j-1] > num[j]) {
				++cnt;
				swap(num[j-1], num[j]);
			}
		}
	}
	return cnt; 
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i=0; i<n; ++i) scanf ("%d", &num[i]);
		int cnt = bubbleSort(num, n);
		for (int i=0; i<n; ++i) {
			if (i) putchar(' ');
			printf ("%d", num[i]);
		}
		printf ("\n%d\n", cnt);
	}
	return 0;
}
