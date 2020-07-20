#include <iostream>
using namespace std;
const int MAX_N = 110;
int j, n, k, x, cnt, a[MAX_N];
bool flag = 0;
void bubbleSort(int A[MAX_N], int N) {
	flag = 1;
	while( flag) {
		flag = 0;
		for (j =N-1;j>0;--j) {
			if( A[j] < A[j-1]) {
				x= A[j];A[j]= A[j-1];A[j-1]=x;
				cnt++;
				flag = 1;
			}
		}
	}
	for (k = 0; k < N-1; ++k) {
		cout << A[k] << " ";
	}
	cout<<A[N-1]<<endl;
	cout<<cnt<<endl;
}
int main() {
	cnt=0;
	cin>>n;
	for (j = 0; j < n; ++j) {
		cin >> a[j];
	}
	bubbleSort(a, n);
	return 0;
}
