#include<iostream>
#include<vector>
#define rep(i, n) rep2(i,0,n)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

void insertionSort(vector<int>a, int n) {
	rep2(i,1, n) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		rep(i, n-1 )cout << a[i] << " ";
		cout <<a[n-1]<< endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> r(n);
	for(int i=0;i<n;++i) {
		cin >> r[i];
	}
        rep(i, n-1 )cout << r[i] << " ";
		cout <<r[n-1]<< endl;
	insertionSort(r, n);
	
	}

