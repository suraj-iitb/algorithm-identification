#include <iostream>
#include <vector>

using namespace std;

class Solver {

};

int cnt = 0;

vector<int> merge(vector<int> left, vector<int>right) {
	vector<int> ret(left.size() + right.size());
	int left_i = 0;
	int right_i = 0;
	for (int i = 0; i < ret.size(); i++) {
		if (right_i == right.size()) {
			ret[i] = left[left_i];
			left_i++;
		}
		else if (left_i == left.size()) {
			ret[i] = right[right_i];
			right_i++;
		}
		else if (left[left_i] <= right[right_i]) {
			ret[i] = left[left_i];
			left_i++;
		}
		else {
			ret[i] = right[right_i];
			right_i++;
		}
		cnt++;
	}
	return ret;
}

vector<int> mergeSort(vector<int> ar) {
	if (ar.size() == 1)return ar;
	int mid = ar.size() / 2;
	vector<int> left(mid);
	vector<int> right(ar.size() - mid);
	for (int i = 0; i < ar.size(); i++) {
		if (i < mid)left[i] = ar[i];
		else right[i - mid] = ar[i];
	}

	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	vector<int> sorted = mergeSort(ar);
	for (int i = 0; i < n; i++) {
		cout << sorted[i];
		if (i < n - 1)cout << " ";
	}
	cout << endl;

	cout << cnt << endl;
}
