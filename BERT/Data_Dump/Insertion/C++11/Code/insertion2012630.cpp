#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int a;
	cin >> a;
	vector<int>s(a);
	for (int b = 0; b < a; b++)cin >> s[b];
	auto c = s.begin();
	c++;
	for (;; c++) {
		sort(s.begin(), c);
		for (int p = 0; p < a - 1; p++)cout << s[p] << " ";
		cout << s[a-1] << endl;
		if (c == s.end())break;
	}
}
