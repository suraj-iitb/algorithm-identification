#include<iostream>
#include <climits>
#include<vector>
#include<list>
#include<numeric>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;


int partition(vector<pair<char,int>> &A, int p, int r) {
	int x = A[r].second;
	int i = p - 1;
	for (int j = p;j < r;j++) {
		if (A[j].second <= x) {
			i++;
			pair<char,int> tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	pair<char,int> tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	return i + 1;
}

void quickSort(vector<pair<char,int>> &A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<char, int>> A(n);
	map<int, queue<char>> qu;
	REP(i, n) {
		cin >> A[i].first >> A[i].second;
		qu[A[i].second].push(A[i].first);
	}
	quickSort(A, 0, n - 1);
	bool stable = true;
	REP(i, n - 1) {
		if (A[i].first == qu[A[i].second].front()) qu[A[i].second].pop();
		else {
			stable = false;
			break;
		}
	}
	if (stable) cout << "Stable\n";
	else cout << "Not stable\n";
	REP(i, n) {
		cout << A[i].first << " " << A[i].second << "\n";
	}

	return 0;
}
