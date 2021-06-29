#include <iostream>

using namespace std;
int main() {
	int A[100];
	int n, i, j;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> A[i];
	}
	for(int t=0; t<n-1; t++){
		cout << A[t] << ' ';
	}
	cout << A[n-1] << endl;
	for(i=1; i<n; i++){
		int v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(int t=0; t<n-1; t++){
			cout << A[t] << ' ';
		}
		cout << A[n-1] << endl;
	}
}
