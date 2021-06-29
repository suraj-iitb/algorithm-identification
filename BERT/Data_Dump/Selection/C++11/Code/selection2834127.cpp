#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
static const int MAX = 100;
static int changeCt = 0;

void selectionSort(int T[], int n) {
	for (int i = 0; i <= n - 1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (T[min] > T[j]) {
				min = j;
			}
		}
		if(i != min) {
			swap(T[i], T[min]);
			changeCt++;
		}
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
	selectionSort(A, n);
	for (int ct = 0; ct < n - 1; ct++) cout << A[ct] << ' ';
	cout << A[n - 1] << endl;
	cout << changeCt << endl;

	return 0;
}
