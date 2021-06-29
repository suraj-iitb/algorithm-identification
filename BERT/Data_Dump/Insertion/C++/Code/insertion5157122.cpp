#include <iostream>

using namespace std;

const int N = 1e5;
int A[N], n;

void sort(){
	int i, j;
	for (i = 2; i <= n; ++i){
		if (A[i] < A[i - 1]){
			A[0] = A[i];
			for (j = i - 1; A[0] < A[j]; --j){
				A[j+1] = A[j];
			}			
			A[j+1] = A[0];
		}
		for (int k = 1; k < n; ++k){
			cout << A[k] << " ";
		}  
    	cout << A[n] << endl;
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	for(int i = 1; i < n; ++i) cout << A[i] << " ";
	cout << A[n] << endl;
	sort();
	return 0;
}
