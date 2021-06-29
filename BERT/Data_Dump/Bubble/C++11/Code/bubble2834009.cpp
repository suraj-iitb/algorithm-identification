#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
static const int MAX = 100;
static int changeCt = 0;
void BubbleSort(int T[], int n) {
	bool flag = true;
	while(flag) {
		flag = false;
		for(int j = n-1; j >= 1; j--) {
			if(T[j] < T[j-1]) {
				swap(T[j], T[j-1]);
				flag = true;
				changeCt++;
			}
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
	BubbleSort(A, n);
	for (int ct = 0; ct < n - 1; ct++) cout << A[ct] << ' ';
	cout << A[n - 1] << endl;
	cout << changeCt << endl;
	
	return 0;
}
