#include <iostream>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdio>
using namespace std;

void print(int* a,int n){
	for (int s = 0;;){
		cout << a[s];
		s++;
		if (s >= n)break;
		cout << ' ';
	}
}

void InsertionSort(int* a,int n){
	for (int i = 1; i < n;){
		int v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = v;

		print(a,n);

		i++;
		cout << endl;
	}
}

int main(){

	int n, a[1001];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}

	print(a, n); cout << endl;

	InsertionSort(a, n);

	return 0;
}
