#include <iostream>
#include <cstdio>
#define MAX_N 100
using namespace std;

void swap(int &a, int &b);
void display(int ary[], int size);
int bubbleSort(int ary[], int size);

int main(void) {
	int N;
	int ary[MAX_N];

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> ary[i];
	}

	int cnt = bubbleSort(ary, N);
	printf("%d\n", cnt);

	return 0;
}

void display(int ary[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%d", ary[i]);
		if(i == size-1) putchar('\n');
		else            putchar(' ');
	}
}

int bubbleSort(int ary[], int size) {
	bool flag = true;
	int cnt = 0;
	while(flag) { 
		flag = false;
		for(int j = size-1; j > 0; j--) {
			if(ary[j] < ary[j-1]) {
				swap(ary[j], ary[j-1]);
				cnt++;
				flag = true;
			}
		}
	}
	display(ary, size);
	return cnt;
}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
