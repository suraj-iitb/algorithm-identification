#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
#include <cctype>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int N;
	vector<int> A;
	int key;
	int j;

	cin >> N;

	A.reserve(N);
	REP(i, N) {
		cin >> A[i];
	}


	// 様子を表示
	REP(k, N) {
		cout << A[k];
		if(k != N - 1) cout << ' ';
		else cout << endl;
	}

	for(int i = 1; i < N; ++i) {

		key = A[i];
		j = i;

		// keyの挿入位置を決める
		while (A[j - 1] > key && j > 0) {
			// key挿入するために一個ずつずらしてく
			A[j] = A[j - 1];
			--j;
		}
		// key挿入
		A[j] = key;

		REP(k, N) {
			cout << A[k];
			if(k != N - 1) cout << ' ';
			else cout << endl;
		}


	}

	return 0;
}
