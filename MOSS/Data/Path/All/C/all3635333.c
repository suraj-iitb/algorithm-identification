#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include <random>
#include <list>
#include <numeric>



#define rep(i,p,q) for(i = p;i < q;i++)
#define ll long long

using namespace std;

int v, e;


int main(void) {
	cin >> v >> e;
	
	int i;
	ll d[100][100];
	int j;
	rep(i, 0, 100) {
		rep(j, 0, 100) {
			d[i][j] = i == j ? 0 : 1e11;
		}
	}
	rep(i, 0, e) {
		int s, t, w;
		cin >> s >> t >> w;
		d[s][t] = w;
	}

	int k;
	bool negative = false;
	rep(i, 0, v) {
		rep(j, 0, v) {
			rep(k, 0, v) {
				if (d[j][i] != 1e11 && d[i][k] != 1e11) {
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
				}
				
			}
		}
	}

	rep(i, 0, v) {
		if (d[i][i] < 0) {
			negative = true;
			break;
		}
	}

	if (negative) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		rep(i, 0, v) {
			rep(j, 0, v - 1) {
				string ans = d[i][j] != 1e11 ? to_string(d[i][j]) : "INF";
				cout << ans << " ";
			}
			string ans = d[i][j] != 1e11 ? to_string(d[i][j]) : "INF";
			cout << ans << endl;
		}
	}
	
}
