/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
using namespace std;

int selectionSort(int *a, int n){
	int tmp;
	int minj;
	int count = 0;
	for(int i=0; i< n; ++i){
		minj = i;
		for(int j=i; j<n; ++j){
			if (a[j] < a[minj]){
				minj = j;
			}
		}
		if (i != minj){
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			++count;
		}
	}
	return count;
}

int main(){
	int n, count;
	cin >> n;
	int *a = new int[n];

	for (int i =0; i<n; ++i){
		cin >> a[i];
	}

	count = selectionSort(a, n);

	for(int i=0; i<n-1; ++i){
		cout << a[i] <<" ";
	}
	cout << a[n-1] << endl;
	cout << count << endl;

	return 0;
}


