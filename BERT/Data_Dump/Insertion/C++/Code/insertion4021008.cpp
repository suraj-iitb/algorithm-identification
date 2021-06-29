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

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	rep(i,N) {
		cin >> A[i];
	}
	for (int i = 1; i < N ;++i) {
		int v = A[i];
		int j = i - 1;
		rep(i, N - 1)cout << A[i] << " ";
		cout << A[N - 1] << endl;
		while (0<=j&&v<A[j])
		{
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
	}
	rep(i, N - 1)cout << A[i] << " ";
	cout << A[N - 1] << endl;
	return 0;
}


