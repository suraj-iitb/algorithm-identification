#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void CountingSort(vector<int> ary1, vector<int>& ary2, int k) {
	int n = ary1.size();
	vector<int> ary3(k);

	for (int i = 0; i < k; i++) ary3[i] = 0;

	for (int i = 0; i < n; i++) ary3[ary1[i]]++;

	for (int i = 1; i < k; i++) ary3[i] = ary3[i] + ary3[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		ary2[ary3[ary1[i]] - 1] = ary1[i];
		ary3[ary1[i]]--;
	}
	return;
}


int main() {

	int n = 0, max = 0, isf = 0;
	cin >> n;
	vector<int> ary1(n);
	vector<int> ary2(n);

	for (int i = 0;i < n;i++) {
		cin >> ary1[i];
		if (ary1[i] > max) max = ary1[i];
	}

	CountingSort(ary1, ary2, max + 1);
	string p;
	for (int i = 0;i < n;i++) {
		if (isf++) p += " ";
		p += to_string(ary2[i]);
	}

	cout << p << endl;
	return 0;
}

