#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[500005];
ll sum = 0;

void merge(int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	vector<ll> L, R;
	REP(i, n1)
	{
		L.push_back(S[left + i]);
	}
	REP(i, n2)
	{
		R.push_back(S[mid + i]);
	}
	L.push_back(INF); R.push_back(INF);
	int i = 0, j = 0;
	FOR(k, right, left)
	{
		++sum;
		if (L[i] <= R[j])
		{
			S[k] = L[i++];
		}
		else
		{
			S[k] = R[j++];
		}
	}
}

void mergeSort(int left, int right)
{
	if (left + 1 >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid, right);
	merge(left, mid, right);
}

int main()
{
	int n;
	cin >> n;
	REP(i, n)
	{
		cin >> S[i];
	}
	mergeSort(0, n);
	cout << S[0];
	FOR(i, n, 1)
	{
		cout << " " << S[i];
	}
	cout << endl << sum << endl;
	return 0;
}
