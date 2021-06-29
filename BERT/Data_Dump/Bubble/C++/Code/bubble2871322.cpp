#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int bubble_sort(int *data, int n)
{
	int flag = 1;
	int count = 0;
	int i = 0;
	while(flag) {
		flag = 0;
		for(int j = n-1; j > i; j--) {
			if(data[j] < data[j-1]) {
				swap(data[j], data[j-1]);
				flag = 1;
				count++;
			}
		}
		i++;
	}
	return count;
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

	int change = bubble_sort(data, n);

	for(int i = 0; i < n; i++) {
		if(i != 0) cout << ' ';
		cout << data[i];
	}
	cout << endl;
	cout << change << endl;

	delete data;	
	return 0;
}
