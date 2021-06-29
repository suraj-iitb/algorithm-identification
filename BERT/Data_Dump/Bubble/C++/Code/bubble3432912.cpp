#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100;

int main(){
	
	int n;
	cin >> n;
	int A[MAX];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int count = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = n - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				int temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				flag = 1;
				count++;
			}
		}
	}

	for (int i = 0; i < n-1; i++) {
		cout << A[i] << ' ';
	}
	cout << A[n - 1] << endl;
	cout << count << endl;
	
	return 0;
}
