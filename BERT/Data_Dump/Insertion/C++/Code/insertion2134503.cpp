#include <iostream>
#include <cstdio>
#define MAX_N 100
using namespace std;

void display(int *aryptr, int size) {
	while(size > 0) {
		printf("%d", *aryptr);
		size--;
		if(size == 0) putchar('\n');
		else          putchar(' ');
		aryptr++;
	}
}

int main(void) {
	int N;
	int ary[MAX_N];

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> ary[i];
	}

	for(int i = 0; i < N; i++) {
		int v = ary[i];
		int j = i - 1;

		while(j >= 0 && ary[j] > v) {
			ary[j+1] = ary[j];
			j--;
		}
		ary[j+1] = v;
		display(ary, N);
	}
	return 0;
}
