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
	int s = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i+1; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;;
			}
		}
		swap(A[i], A[minj]);
		if (i != minj)s++;
	}
	for (int i = 0; i < n-1; i++) {
		cout << A[i] << ' ';
	}
	cout << A[n - 1] << endl << s << endl;
}
