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
	int c = 0;
	int temp;
	int min;

	cin >> N;
	A.reserve(N);

	REP(i, N)
		cin >> A[i];

	REP(i, N) {
		min = i;
		for(int j = i + 1; j < N; ++j) {
			if(A[j] < A[min]) {
				min = j;
			}
		}

		if(min != i) {
			temp = A[min];
			A[min] = A[i];
			A[i] = temp;
			++c;
		}
	}

	REP(i, N) {
		cout << A[i];
		(i != N - 1)?
			cout << ' ' : cout << endl;
	}
	cout << c << endl;
	return 0;
}
