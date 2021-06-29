#include<iostream>
#include <string>
#include <cstdlib> //絶対値利用のため
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)

//const int INF = INT_MAX / 2;

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << a[0];
	for (int i = 1; i < n; i++) cout << " " << a[i];
	cout << endl;
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while(j >=0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = v;
		cout << a[0];
		for (int i = 1; i < n; i++) cout << " " << a[i];
		cout << endl;
	}

	return 0;
}
