#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,from,to) for(int i=from; i<to; ++i)
#define REP(i,from,to) for(int i=from; i<=to; ++i)
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> area;
typedef struct answer answer;
template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i] << endl;
	}
	return out;
}
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

const int maxn = 110;
int n;
int a[maxn];
void print(int arr[maxn]) {
	for (int i = 0; i < n - 1; ++i) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1] << endl;
}
void insertionSort(int arr[maxn]) {
	print(arr);
	REP(i,1,n-1)
	{
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		print(arr);
	}
}

void solve() {
	cin >> n;
	rep(i,0,n)
	{
		cin >> a[i];
	}
	insertionSort(a);
}

int main() {
	solve();
}
