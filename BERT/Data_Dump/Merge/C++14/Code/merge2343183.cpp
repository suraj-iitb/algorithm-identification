#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cfloat>
#include <cmath>
#include <functional>
#include <forward_list>
#include <list>


#define DEBUG(x) cout << #x << "\t:" << x << endl;
#define EPS (1e-9)
#define INF (INT_MAX/3)
#define MOD 1000000007
#define PI 3.14159265358979
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REPV(it,v) for(auto it = (v).begin(); it != (v).end(); ++it)

#define NUM 5000

#define ll long long
#define ull unsigned long long

using namespace std;

typedef pair<int, int> iiPair;


class Main {
public:
	int compare = 0;

	vector<int> merge(vector<int>& as, vector<int>& bs) {
		vector<int> ret;

		int ia=0;
		int ib=0;
		while (ia < as.size() && ib < bs.size()) {
			if (as[ia] <= bs[ib]) {
				ret.push_back(as[ia]);
				ia++;
				compare++;
			}
			else {
				ret.push_back(bs[ib]);
				ib++;
				compare++;
			}
		}

		while (ia < as.size()) {
			ret.push_back(as[ia]);
			ia++;
			compare++;
		}

		while (ib < bs.size()) {
			ret.push_back(bs[ib]);
			ib++;
			compare++;
		}

		return ret;
	}

	vector<int> mergeSort(vector<int>& as) {
		if (as.size() <= 1) {
			return as;
		}

		int mid = as.size() / 2;
		vector<int> former, latter;
		REP(i, as.size()) {
			if (i < mid) {
				former.push_back(as[i]);
			}
			else {
				latter.push_back(as[i]);
			}
		}

		former = mergeSort(former);
		latter = mergeSort(latter);
		vector<int> ret = merge(former, latter);

		return ret;
	}
};

int main(void) {
	Main main;
	int n;
	vector<int> as;
	cin >> n;
	REP(i, n) {
		int inp;
		cin >> inp;
		as.push_back(inp);
	}

	auto ans = main.mergeSort(as);
	REP(i, n) {
		cout << ans[i];
		if (i <= n - 2) cout << " ";
	}
	cout << endl;
	cout << main.compare << endl;

	return 0;
}
