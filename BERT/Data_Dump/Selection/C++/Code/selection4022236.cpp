#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef long double ld;


void selectionSort(vector<int> A,int N) { // N 個の要素を含む 0-オリジンの配列 A
	int count = 0;
	for (int i = 0; i < N-1;++i) {
		int minj = i;
		for (int j = i; j < N ;++j) {
			if (A[j]<A[minj]) {
				minj = j;
			}
		}
		if (i!=minj) {
			int tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			count++;
		}
	}
	rep(i,N-1) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	cout << count << endl;
}
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) {
		cin >> a[i];
	}
	selectionSort(a,N);
	return 0;
}



