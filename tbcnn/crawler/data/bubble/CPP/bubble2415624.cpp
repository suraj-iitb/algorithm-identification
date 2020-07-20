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
typedef long long ll;
using namespace std;

int a[100];

int  bubbleSort(int a[],int n) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	//freopen("run.in", "r", stdin);
	//freopen("run.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = bubbleSort(a, n);
	
	cout << a[0];
	for (int i = 1; i < n; i++)
		cout<<' '<< a[i];
	cout << endl;
        cout << ans << endl;


	return 0;

}
