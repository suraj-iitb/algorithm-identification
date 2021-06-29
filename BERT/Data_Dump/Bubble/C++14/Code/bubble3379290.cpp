#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long int

#define rep(p,q) for(int i = p; i < q;i++)


int main(void) {
	int n;
	vector<int> vec = vector<int>();
	cin >> n;
	rep(0, n) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	bool flag = true;
	int count = 0;
	while (flag) {
		flag = false;
		for (int i = n - 1; 0 < i; i--) {
			if (vec[i] < vec[i - 1]) {
				int tmp = vec[i];
				vec[i] = vec[i - 1];
				vec[i - 1] = tmp;
				flag = true;
				count++;
			}
		}
	}
	rep(0, n - 1) cout << vec[i] << " ";
	cout << vec[n - 1] << endl << count << endl;
}
