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
using namespace std;

int a[100];
signed main() {
	int b; cin >> b;
	for (int c = 0; c < b; c++)cin >> a[c];
	for (int i = 1; i <= b; i++) {
		sort(a, a + i);
		for (int j = 0; j < b; j++) {
			if (j)cout << " ";
			cout << a[j];
		}
		cout << endl;
	}
}
