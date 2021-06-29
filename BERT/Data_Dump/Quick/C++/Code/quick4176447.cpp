#include <vector>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

int partition(vector<pair<int, char> >& A, int p, int r)
{
	pair<int, char> x = A[r];
	int i = p - 1;
	for (size_t j=p; j<r; j++) {
		if (A[j].first <= x.first) {
			i++;
			pair<int, char> tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	pair<int, char> tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i+1;
}

void quicksort(vector<pair<int, char> >& A, int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int main(void)
{
	int n;
	vector<pair<int, char> > A;
	map<int, vector<char> > order;
	cin >> n;
	for (int i=0; i<n; i++) {
		int t;
		char c;
		cin >> c;
		cin >> t;
		A.push_back(pair<int, char>(t, c));

		try {
			order.at(t).push_back(c);
		} catch (const out_of_range&) {
			vector<char> tmp;
			tmp.push_back(c);
			order[t] = tmp;
		}
	}

	quicksort(A, 0, n-1);

	bool stable = true;

	map<int, int> check;
	for (int k=0; k<n; k++) {
		if (stable) {
			int idx = check[A[k].first];
			//cout << idx << endl;
			//cout << "? " << order[A[k].first][idx] << " != " << A[k].second << endl;
			if (order[A[k].first][idx] != A[k].second) stable = false;
			check[A[k].first]++;
		}
	}

	cout << (stable ? "Stable" : "Not stable") << endl;

	for (int k=0; k<n; k++) {
		cout << A[k].second << " " << A[k].first << endl;
	}

	return 0;
}
