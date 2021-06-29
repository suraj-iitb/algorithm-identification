#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(int *data, int n)
{
	for(int i = 1; i < n; i++) {
		int v = data[i];
		int j = i - 1;
		while(j >=0 && data[j] > v) {
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = v;
		for(int i = 0; i < n; i++) {
			printf("%d", data[i]);
			if(i != n-1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	int *data;
	data = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> data[i];
	}

	for(int i = 0; i < n; i++) {
		printf("%d", data[i]);
		if(i != n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	insertion_sort(data, n);
	delete data;
	return 0;
}
