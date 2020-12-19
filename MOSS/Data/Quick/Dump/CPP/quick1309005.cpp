#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
const double EPS=1e-9;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};


class card {
public:
	char c;
	int d;
	int id;
};

template<typename T>
int partition(std::vector<T> &A, int p, int r, bool (*f)(T, T) ) {
	T x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (f(A[j], x)) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

template<typename T>
void quicksort(std::vector<T> &A, int p, int r, bool (*f)(T, T) ) {
	if (p >= r) return;
	int q = partition(A, p, r, f);
	quicksort(A, p, q - 1, f);
	quicksort(A, q + 1, r, f);
}


int main(int argc, char const *argv[]) {
	int N;
	cin >> N;

	std::vector<card> array;
	for (int i = 0; i < N; ++i) {
		char c;
		int d;
		cin >> c >> d;
		array.push_back((card){c, d, i});
	}

	quicksort<card>(array, 0, N - 1, 
		[](card a, card b){
			return a.d <= b.d;
		}
	);

	bool stable = true;
	for (int i = 0; i < N - 1; ++i) {
		if (array[i].d == array[i + 1].d && array[i].id > array[i + 1].id) {
			stable = false;
		}
	}
	if (stable) {
		cout << "Stable" << endl;
	} else {
		cout << "Not stable" << endl;
	}
	for (int i = 0; i < N; ++i) {
		cout << array[i].c << " " << array[i].d << endl;
	}
	return 0;
}
