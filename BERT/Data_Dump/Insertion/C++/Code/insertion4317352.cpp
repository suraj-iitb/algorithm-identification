#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; i++)
#define rep_1(i, n) for(int i=1; i<n; i++)
using namespace std;

int main() {
	int n, tmp;
	vector<int> a;
	cin >> n;
	rep(i, n) {
		cin >> tmp;
		a.push_back(tmp);
	}
	// cout << "start func" << endl;
	void insertion_sort(vector<int> a, int n);
	insertion_sort(a, n);
}

void insertion_sort(vector<int> a, int n) {
	void out_result(vector<int> a, int n);
	rep_1(i,n) {
		int tmp = a[i];
		int j = i-1;
		out_result(a, n);
		while(j>=0 && a[j]>tmp) {
			a[j+1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
	out_result(a, n);
}

void out_result(vector<int> a, int n) {
	rep(i, n-1) cout << a[i] << " ";
	cout << a[n-1] << endl;	
}
