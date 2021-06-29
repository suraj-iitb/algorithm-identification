#include <iostream>
#include <algorithm>
#include <string>
#include <cmath> 
#include <vector>
#include <iomanip>
#include <locale>

const double PI = 3.141592653589;

using namespace std;

void bubbleSort(vector<int> a) {
	bool flag = true;
	int tmp, count = 0;
	while (flag) {
		flag = false;
		for (int j = a.size() - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				flag = true;
				count++;
			}
		}
	}

	//表示
	for (int i = 0; i < a.size()-1; i++) {
		cout << a[i] << " ";
	}
	cout << a[a.size() - 1] << endl;
	cout << count << endl;
	
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)	cin >> a[i];

	bubbleSort(a);

	return 0;
}

