/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
#include <algorithm>
#include <utility>
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

	int flag = 1;
	int count = 0;
	int tmp;
	for (int i=0; flag; ++i){
		flag = 0;
		for (int j=0; j<n-i-1; ++j){
			if (a[j] > a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	trace(a, n);
	cout << count << endl;

	return 0;
}

