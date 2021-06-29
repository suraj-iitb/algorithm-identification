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

int n;
vector<int> S;
vector<int> temp;
int c;

const long long INF = 1 << 30;
#define REP(i,n) for(int i = 0; i < (int)n; ++i)

void Merge(int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1 + 1], R[n2 + 1];

	REP(i, n1)
		L[i] = S[left + i];
	REP(i, n2)
		R[i] = S[mid + i];

	L[n1] = INF;
	R[n2] = INF;

	int ii = left;
	int j = 0, k = 0;
	for(; ii < right; ++ii) {
		++c;
		if(L[j] <= R[k])
			S[ii] = L[j++];
		else
			S[ii] = R[k++];
	}
}

void MergeSort(int left, int right)
{
	if(left + 1 < right) {
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid, right);
		Merge(left, mid, right);
	}
}

int main()
{
	cin >> n;
	S.reserve(n);
	temp.reserve(n);
	REP(i, n)
		cin >> S[i];

	MergeSort(0, n);

	// 出力
	REP(i, n) {
		cout << S[i];
		(i != n - 1)?
			cout << ' ' : cout << endl;
	}
	cout << c << endl;
	return 0;
}
