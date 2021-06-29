#include<bits/stdc++.h>
using namespace std;
int N;

void Print(vector<int> A) {
	for(int i=0; i<N-1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N-1] << endl;
}

void InsertSort(vector<int> A) {
	for(int i=1; i<N; i++) {
		int j = i;
		while(j>0 && A[j-1] > A[j]) {
			swap(A[j], A[j-1]);
			--j;
		}
	Print(A);
	}
}

int main() {
	cin >> N;
	vector<int> A(N);
	for(int i=0; i<N; i++) cin >> A[i];
	Print(A);
	InsertSort(A);
}

