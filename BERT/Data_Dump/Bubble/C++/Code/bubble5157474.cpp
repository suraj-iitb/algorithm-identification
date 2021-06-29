#include <iostream>

using namespace std;

const int N = 1e5;
int A[N], n, num;

void sort(){
	for(int i = 0; i < n; ++i)
		for(int j = n-1; j > i; --j){
			if (A[j] < A[j-1]){
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				num++;
			}
		}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> A[i];
	sort();
	for(int i = 0; i < n-1; ++i) cout << A[i] << " ";
	cout << A[n-1] << endl;
	cout << num << endl;
	return 0;
}
