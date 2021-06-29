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

int selectionSort(int num[], int n) {//???????????? 
	int cnt = 0; //?????蔵?測???属 
	for (int i=0; i<n; ++i) {
		int k = i;
		for (int j=i+1; j<n; ++j) {
			if (num[k] > num[j]) k = j;
		}
		if (k != i) swap(num[k], num[i]), ++cnt;
	}
	return cnt;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i=0; i<n; ++i) scanf ("%d", &num[i]);
		int cnt = selectionSort(num, n);
		for (int i=0; i<n; ++i) printf (i ? " %d" : "%d", num[i]);
		printf ("\n%d\n", cnt);
	}
	return 0;
}
