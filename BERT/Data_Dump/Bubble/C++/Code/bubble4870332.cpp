
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>

/*

bool isOK(int index, int key) {
	if (a[index] >= key) return true;
	else return false;
}
int binary_search(int key) {
	int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;

		if (isOK(mid, key)) ok = mid;
		else ng = mid;
	}
	return ok;
}
*/

//vector<vector<ll> > data(3, vector<ll>(4));
//vector<ll> data(N);
//v.erase(remove(v.begin(), v.end(), value_to_remove), v.end());
//int num = atoi(numStr.c_str());
//str s = to_string(i);
//int i = c - '0'
//sort(data.begin(), data.end());
//reverse(data.begin(), data.end());
//data.erase(unique(data.begin(), data.end()), data.end()); //重複なし
//str.substr(n)//n番以降スライス
//str.substr(n,m)//n番以降m文字スライス
//str.erase(n)//n番以降削除
//str.erase(n,m)//n番以降m文字削除
//str.find(str_to_find)//位置 or string::npos
//cout << fixed << setprecision(15) << n;
//while (cin >> c){if (c == EOF) break;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=ll(a);i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define PB push_back
#define SIZE(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define INF 1000000000000
#define MOD 1000000007
#define PI 3.14159265358979323846

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll bubble(vector<ll> & data) {
	ll i, j,counter;
	ll v;
	ll Counter = 0;

	do{
		counter = 0;
		REP(i, SIZE(data) - 1) {
			v = data[i];
			if(data[i+1]<v){
				data[i] = data[i + 1];
				data[i + 1] = v;
				counter++;
			}
		}
		Counter += counter;
	} while (counter > 0);
	return Counter;
}

ll selection(vector<pair<char, ll> >& data) {
	pair<char, ll> minv;
	ll minn;
	ll counter = 0;
	REP(i, SIZE(data) - 1) {
		minn = i;
		minv = data[i];
		FOR(j, i + 1, SIZE(data) - 1) {
			if (minv.second > data[j].second) {
				minv = data[j];
				minn = j;
			}
		}
		if (minn != i) {
			data[minn] = data[i];
			data[i] = minv;
			counter++;
		}
	}
	return counter;
}

bool isStable(vector<pair<char, ll> >& data, vector<pair<char, ll> >& dataa) {
	vector<char> s1, s2;
	FOR(i, 1, 9) {
		REP(j, SIZE(data)) {
			if (i == data[j].second)s1.push_back(data[j].first);
			if (i == dataa[j].second)s2.push_back(dataa[j].first);
		}
	}
	if (s1 == s2) return true;
	else return false;
}

ll gcd(ll a, ll b) {
	ll x = min(a,b), y=max(a,b);
	
	ll z = y % x;
	if (z == 0) return x;
	else return gcd(x, z);
}

bool isprime(ll n) {
	if (n == 2)return true;

	if (n % 2 == 0) return false;

	ll i = 3;
	while (i <= sqrt(n)) {
		if (n % i == 0) return false;
		i += 2;
	}
	return true;
}
int main() {
	ll n,c;
	cin >> n;
	vector<ll> data(n);
	REP(i, n)cin >> data[i];
	c = bubble(data);
	REP(i, n) {
		cout << data[i];
		i == n-1? cout << endl: cout << " ";
	}
	cout << c << endl;
}



