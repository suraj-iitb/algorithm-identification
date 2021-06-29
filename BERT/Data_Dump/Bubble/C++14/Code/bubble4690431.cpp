
#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> &a) {
	int count = 0;
	int n = (int)a.size();
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > i; j--) {
			if (a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
				count++;
			}
		}
	}
	return count;
}

void printVector(vector<int> a) {
	int n = (int)a.size();
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n-1) cout << " ";
	}
	cout << endl;
}

int main() {

	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int ans = bubbleSort(a);
	printVector(a);
	cout << ans << endl;

	return 0;
}

