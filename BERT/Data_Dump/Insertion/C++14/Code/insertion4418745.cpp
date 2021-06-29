#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <map>
#include<set>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0;i < N;i++) {
		cin >> A.at(i);
	}

	for (int k = 0; k < N;k++) {
		cout << A.at(k);
		if (k < N - 1)cout << " ";
		else cout << endl;
	}
	for (int i = 1;i < N; i++) {
		int v = A.at(i);
		for (int j = i - 1;j >= 0;j--) {
			if (v < A.at(j)) {
				A.at(j + 1) = A.at(j);
				A.at(j) = v;
			}
		}
		for (int k = 0; k < N;k++) {
				cout << A.at(k);
				if (k < N - 1)cout << " ";
				else cout << endl;
		}
			
		
		
	}
}

