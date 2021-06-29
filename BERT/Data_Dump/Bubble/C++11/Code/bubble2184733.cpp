#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cstring>
using namespace std;

int BIT[151];
void update(int a) {//a???1????¶????
while (a <= 150) {
	BIT[a]++;
	a += a&(-a);
   }
}
int n(int a) {
	int sum = 0;
	while (a>0) {
		sum += BIT[a];
		a -= a&(-a);
	}
	return sum;
}
signed main() {
	int a; cin >> a;
	int s[150];
	int sum = 0;
	for (int i = 0; i < a; i++) {
		int k; cin >> k;
		s[i] = k;
		k++;
		sum += i-n(k);
		update(k);
	}
	sort(s, s + a);
	for (int l = 0; l < a; l++) {
		if (l)cout << " ";
		cout << s[l];
	}
	cout << endl;
	cout << sum << endl;
}
