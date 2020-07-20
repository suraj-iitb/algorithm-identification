#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define p2(x) (x)*(x)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;

const int MAX_N = 110;
int a[MAX_N];
int n;
int sc = 0;

void bubbleSort(int first, int last) {
	for (int i = last - 1 ; i >= first; i--) {
		for (int j = first ; j <= i; j++) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				sc++;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	rep(i, n)
		cin >> a[i];
	bubbleSort(0, n-1);
	rep(i, n) {
		if (i!= n-1)
			cout << a[i] << " ";
		else 
			cout << a[i] << endl;
	}
	cout  << sc << endl ;
	return 0;
}
