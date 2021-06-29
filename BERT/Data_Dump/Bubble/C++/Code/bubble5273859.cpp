#include <iostream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>


using namespace std;


int main(void) {
	int n;
	cin >> n;
	vector<int>A;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	int flag = 1;
	int i = 0;
	int k = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j > i ; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				k++;
			}
		}
		i++;
	}
	for (int j = 0; j < n-1; ++j) {
		cout << A[j] << ' ';
	}
	cout << A[n - 1] << endl;
	cout << k << endl;
}

