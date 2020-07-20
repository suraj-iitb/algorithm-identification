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


int bubbleSort(vector<int> A,int N) { // N 個の要素を含む 0-オリジンの配列 A
	int flag = 1;
	int count = 0;
	int i = 0;
	while (flag) {
		flag = 0;
		for (int j = N - 1;i+ 1 <= j; --j) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				count++;
			}
		}
		i++;
	}
	rep(i, N - 1) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	return count;
}
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) {
		cin >> a[i];
	}
	int count= bubbleSort(a,N);
	cout << count << endl;
	return 0;
}



