#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
static const int MAX = 100;

void insertionSort(int T[], int n) {
	for (int i = 1; i < n; i++) {
		int v = T[i];
		int j = i - 1;
		while ((j >= 0) && (T[j] > v)) {
			T[j + 1] = T[j];
			j--;
		}
		T[j + 1] = v;
		for (int ct = 0; ct < n - 1; ct++) cout << T[ct] << ' ';
		cout << T[n - 1] << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int A[MAX];
	std::string readbuff;
	cin.get();
	getline(cin, readbuff);
	stringstream ss(readbuff);
	string str;
	for (int i = 0; i < n; i++) {
		getline(ss, str, ' ');
		A[i] = stoi(str);
	}
	for (int ct = 0; ct < n - 1; ct++) cout << A[ct] << ' ';
	cout << A[n - 1] << endl;
	insertionSort(A, n);
	return 0;
}
