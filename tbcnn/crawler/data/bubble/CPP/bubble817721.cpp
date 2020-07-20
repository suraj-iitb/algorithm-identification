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
	int temp;
	int c = 0;

	cin >> N;
	A.reserve(N);

	REP(i, N)
		cin >> A[i];

	for(int i = N - 1; i >= 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				++c;
			}
		}
	}
	REP(i, N) {
		cout << A[i];
		(i == N - 1)?
			cout << endl : cout << ' ';
	}

	cout << c << endl;
	return 0;
}
