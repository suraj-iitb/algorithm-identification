#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

struct card {
	int num_;
	char color_;
	int serial_;
};

card A[MAX];
int partition(int p, int r) {
	int X = A[r].num_;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j].num_ <= X) {
			i++;
			swap(A[j], A[i]);
		}
	}
	swap(A[r], A[i + 1]);
	return i + 1;
}
void quick_sort(int p, int r) {
	int q;
	if (p < r) {
		q = partition(p, r);
		quick_sort(p, q - 1);
		quick_sort(q + 1, r);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i].color_ >> A[i].num_;
		A[i].serial_ = i;
	}
	quick_sort(0, n - 1);
	bool is_stable = true;
	for (int i = 0; i < n - 1; i++) {
		if (A[i].num_ == A[i + 1].num_ && A[i].serial_ > A[i + 1].serial_) {
			is_stable = false;
			break;
		}
	}
	cout << (is_stable ? "Stable" : "Not stable") << '\n';
	for (int i = 0; i < n; i++) {
		cout << A[i].color_ << ' ' << A[i].num_<<'\n';
	}
	return 0;
}





