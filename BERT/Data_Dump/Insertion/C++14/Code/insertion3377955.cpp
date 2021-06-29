#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define rep(p,q) for(int i = p;i < q;i++)

#define LL long long int

#define inf 10000000000

//1
int main(void) {
	vector<int> ar = vector<int>();
	int n;
	cin >> n;
	rep(0, n) {
		int a;
		cin >> a;
		ar.push_back(a);
	}
	for (int j = 0; j < n-1; j++)cout << ar[j] << " ";
	cout << ar[n-1] << endl;
	rep(1, n) {
		int v = ar[i];
		for (int j = i - 1; -1 < j && v < ar[j]; j--) {
			ar[j + 1] = ar[j];
			ar[j] = v;
		}
		for (int j = 0; j < n-1; j++)cout << ar[j] << " ";
		cout << ar[n-1] << endl;
	}
}
