#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int n,count=0,row[100];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (row[n - 1 - j] < row[n - 2 - j]) { swap(row[n - 1 - j], row[n - 2 - j]); count += 1; }
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1) { printf("%d\n", row[i]); }
		else { printf("%d ", row[i]); }
	}
	printf("%d\n", count);

	return 0;
}
