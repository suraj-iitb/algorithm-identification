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
	int num;
	int a;
	vector<int>A;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < num; i++) {
		int temp = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > temp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
		for (int k = 0; k < num - 1; k++) {
			cout << A[k] << ' ';
		}
		cout << A[num - 1] << endl;
	}
}
