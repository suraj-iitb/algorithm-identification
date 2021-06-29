#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include<cstdio>
#include <vector>
#include<queue>
#include<limits.h>
#include<string.h>
#include<functional>
#include<map>
#include<set>
#include<list>
#define int long long
using namespace std;

int b[100];
signed main() {
	int a; cin >> a;
	for (int c = 0; c < a; c++) {
		cin >> b[c];
	}
	int ans = 0;
	for (int i = 0; i < a; i++) {
		int     minj = i;
		for (int j = i; j < a; j++) {
			if (b[j] < b[minj]) {
				minj = j;
			}
			
				 }
		swap(b[i], b[minj]);
		if (i != minj)ans++;
	}
	for (int i = 0; i < a; i++) {
		if (i)cout << " ";
		cout << b[i];
	}
	cout << endl;
	cout << ans << endl;
}
