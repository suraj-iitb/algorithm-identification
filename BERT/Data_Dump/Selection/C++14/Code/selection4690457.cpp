#include <iostream>
#include <vector>

using namespace std;

int selectionSort(vector<int> &a) {
	int n = (int)a.size();
	int mini;
	int count = 0;
	for (int i = 0; i < n; i++) {
		mini = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[mini]) mini = j;
		}
		if (i != mini) {
			swap(a[i], a[mini]);
			count++;
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

	int ans = selectionSort(a);
	printVector(a);
	cout << ans << endl;

	return 0;
}


