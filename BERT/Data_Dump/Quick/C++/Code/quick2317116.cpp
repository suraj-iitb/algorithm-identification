

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void myswap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

template<typename T>
int partition(vector<T> &A, int p, int r) {
	int i = p;
	for (int j = p; j < r; j++) {
		if (A[j] <= A[r]) {
			myswap(A[i], A[j]);
			i++;
		}
	}
	myswap(A[i], A[r]);
	return i;
}

template <typename T>
void quick_sort(vector<T> &A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
	else
		return;
}

struct card {
	int number;
	char suit;
};
bool operator < (const card& lhs, const card& rhs) {
	return lhs.number < rhs.number;
}

bool operator > (const card& lhs, const card& rhs) {
	return  rhs < lhs;
}
bool operator <= (const card& lhs, const card& rhs) {
	return !(lhs > rhs);
}
bool operator >= (const card& lhs, const card& rhs) {
	return !(lhs < rhs);
}
bool operator == (const card& lhs, const card& rhs) {
	return (lhs.suit == rhs.suit && lhs.number == rhs.number);
}
bool operator != (const card& lhs, const card& rhs) {
	return !(lhs == rhs);
}


int main() {
	int n = 0;
	cin >> n;
	vector<card> v,v2;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].suit >> v[i].number;
	}
	v2 = v;
	
	quick_sort(v, 0, n - 1);
	stable_sort(v2.begin(), v2.end());
	
	bool is_stable = true;
	for (int i = 0; i < n; i++) {
		if (v[i] != v2[i]) {
			is_stable = false;
			break;
		}
	}
	if (is_stable)
		cout << "Stable\n";
	else
		cout << "Not stable\n";


	for (int i = 0; i < n; i++) {
		cout << v[i].suit << " " << v[i].number << "\n";
	}
	
	return 0;

}
