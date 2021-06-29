#include<iostream>
#include<stdio.h>
using namespace std;
void print(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		cout << a[i];
	}
	cout << endl;
}
void insertionsort(int a[], int n) {
		int i, j, tmp;
		for (i = 1; i < n; i++) {
			tmp = a[i];
			for (j = i; j > 0 && a[j - 1] > tmp; j--) 
				a[j] = a[j - 1];
				a[j] = tmp;
			print(a, n);
		}
	}
int main() {
	int n;
	int a_list[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a_list[i];
	}
	print(a_list, n);
	insertionsort(a_list, n);
}
