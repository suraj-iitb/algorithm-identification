#include <iostream>
#include <vector>
#include <map>

using namespace std;

int partition(vector< pair<int,char> >& A, int p, int r) {
	int x = A[r].first;
	int ind = p-1;
	for (int i = p; i < r; ++i) {
		if (A[i].first <= x) {
			++ind;
			swap(A[i].first,A[ind].first);
			swap(A[i].second,A[ind].second);
		}
	}
	swap(A[r].first,A[ind+1].first);
	swap(A[r].second,A[ind+1].second);
	return (ind+1);
}

void quick_sort(vector< pair<int,char> >& A, int p, int r) {
	if (p < r) {
		int q = partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
	return;
}

int main(void) {
	int n;
	cin >> n;
	map<int,string> ms;
	vector< pair<int,char> > A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i].second;
		cin >> A[i].first;
		ms[A[i].first] += A[i].second;
	}
	quick_sort(A,0,n-1);

	map<int,int> mi;
	bool stable = true;
	for (int i = 0; stable && i < n; ++i) {
		if (ms[A[i].first][mi[A[i].first]] != A[i].second) {
			stable = false;
		}
		else {
			++mi[A[i].first];
		}
	}
	if (stable) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}
	for (int i = 0; i < n; ++i) {
		cout << A[i].second << " ";
		cout << A[i].first << endl;
	}

	return 0;
}

