#include <iostream>

using namespace std;

const int N = 1e5;
int A[N], n, num; 

void selection_sort(){
	for(int i = 1; i <= n; ++i){
		int mini = i;
		for(int j = i; j <= n; ++j){
			if (A[j] < A[mini]) mini = j;
		}
		if (i != mini){
			swap(A[i], A[mini]);
			num++;	
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	selection_sort();
	for(int i = 1; i < n; ++i) cout << A[i] << " ";
	cout << A[n] << endl;
	cout << num << endl;
	return 0;
}
