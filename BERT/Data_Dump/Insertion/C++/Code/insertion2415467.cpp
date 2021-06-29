#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;

typedef long long ll;
int a[100];


int main() {
	//freopen("run.in", "r", stdin);
	//freopen("run.out", "w", stdout);

	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		cout << a[0];
		for (int i = 1; i < n; i++) {
			cout << ' ' << a[i];
		}
		cout << endl;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] < a[j]) {
					int temp = a[i];
					for (int k = i; k >= j + 1; k--) {
						a[k] = a[k - 1];
					}
				
					a[j] = temp;
				
				}
			
			}
			cout << a[0];
			for (int i = 1; i < n; i++) {
				cout << ' ' << a[i];
			}
			cout << endl;
		}
	}


	return 0;

}
