#include<iostream>
#include<vector>
#include<random>
#include<unordered_map>
using namespace std;

struct card {
	char mark;
	int num;
	int idx;
};

int partition(vector<card>& arr, int left, int right) {
	const int pivot = arr[right].num;
	int pivotIndex = left - 1;

	for (int i = left; i < right; i++) {
		if (arr[i].num <= pivot) {
			pivotIndex++;
			swap(arr[i], arr[pivotIndex]);
		}
	}
	swap(arr[right], arr[++pivotIndex]);

	return pivotIndex;
}

void quicksort(vector<card>& arr, int left, int right) {

	if (left >= right) return;

	int pivotIndex = partition(arr, left, right);

	quicksort(arr, left, pivotIndex - 1);
	quicksort(arr, pivotIndex + 1, right);
}


int main() {
	int N;
	cin >> N;
	vector<card> quick(N);
	unordered_map<int, int> mp;

	for (int i = 0; i < N; i++) {
		cin >> quick[i].mark >> quick[i].num;
		mp[quick[i].num]++;
		quick[i].idx = mp[quick[i].num];
	}

	quicksort(quick, 0, N-1);

	bool stable = true;
	mp.clear();
	for (int i = 0; i < N; i++) mp[quick[i].num] = 1;
	for (int i = 0; i < N; i++) {
		if (mp[quick[i].num] != quick[i].idx) stable = false;
		else mp[quick[i].num]++;
	}

	if (stable) cout << "Stable" << '\n';
	else cout << "Not stable" << '\n';
	for (auto c : quick) cout << c.mark << " " << c.num << '\n';
}
