/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
#include <algorithm>
using namespace std;

void trace(int* intArray, int arraySize){
	cout << intArray[0];
	for (int i = 1; i < arraySize; ++i){
		cout << " " << intArray[i];
	}
	cout << "\n";
}

int main(){
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int v, j;
	trace(a, n);
	for (int i=1; i<n; ++i){
		v = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > v)){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		trace(a, n);
	}

	return 0;
}

