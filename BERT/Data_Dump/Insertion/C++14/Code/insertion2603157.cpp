//============================================================================
// Name        : InsertionSort.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> A,int N)
{
	int v;

	for(size_t i = 0; i < A.size(); ++i){
		if(i == A.size()-1){
			cout << A[i] << endl;
			break;
		}
		cout << A[i] << " ";
	}

	for(int i = 1; i < N ; i++){
		v = A[i];
		int j = i - 1;
		while(j >= 0  && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		for(size_t i = 0; i < A.size(); ++i){
			if(i == A.size()-1){
				cout << A[i] << endl;
				break;
			}
			cout << A[i] << " ";
		}
	}
}

int main() {
	int n;
	vector<int> v;

	cin >> n;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		v.push_back(val);
	}

	InsertionSort(v,n);

	return 0;
}
