#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int selection_sort(int *data, int n)
{
	int change = 0;
	for(int i = 0; i < n-1; i++) {
		int min_j = i;
		for(int j = i+1; j < n; j++) {
			if(data[min_j] > data[j]) {
				min_j = j;
			}
		}
		swap(data[i], data[min_j]);
		if(min_j != i) change++;
	}

	return change;
}

int main(void)
{
	int *data;
	int n;

	cin >> n;
	data = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> data[i];
	}

	int change = selection_sort(data, n);

	for(int i = 0; i < n; i++) {
		if(i) cout << " ";
		cout << data[i];
	}
	cout << endl;
	cout << change << endl;

	delete data;
	return 0;
}
