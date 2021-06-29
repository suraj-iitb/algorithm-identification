#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100;

int num[N];

void insertSort(int num[], int n) {
	for (int i=0; i<n; ++i) {
		int j, ns = num[i];
		for (j=i-1; j>=0 && ns<num[j]; --j) num[j + 1] = num[j];
		num[j + 1] = ns;
		for (j=0; j<n; ++j) {
			if (j) printf (" ");
			printf ("%d", num[j]);
		}
		printf ("\n");
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i=0; i<n; ++i) scanf ("%d", &num[i]);
		insertSort(num, n);
	}
	return 0;
}
