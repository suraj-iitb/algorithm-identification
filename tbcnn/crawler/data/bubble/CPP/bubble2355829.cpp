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
void print(int arr[maxn], int n) {
	for (int i = 0; i < n - 1; ++i) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1] << endl;
}

void bubbleSort(int arr[maxn], int n) {
	int cnt = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	print(arr, n);
	cout << cnt << endl;
}

void insertionSort(int arr[maxn], int n) {
	print(arr, n);
	REP(i,1,n-1)
	{
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		print(arr, n);
	}
}

void solve() {
	cin >> n;
	rep(i,0,n)
	{
		cin >> a[i];
	}
	bubbleSort(a, n);
}

int main() {
	solve();
}
