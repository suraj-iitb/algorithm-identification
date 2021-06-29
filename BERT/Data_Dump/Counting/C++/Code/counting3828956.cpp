#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<deque>
#include<map>
#include<set>
#define ll long long
#define dou(s) atof(s.c_str())
#define lon(s) atoll(s.c_str())
#define str(n) to_string(n)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define ALL(a) a.begin(),a.end()
#define fion(n) fixed<<setprecision(n)
#define endl "\n"
#define OR ||
#define AND &&
#define NOT !
#define line(s) getline(cin,s)
#define MOD 1000000007
#define fdarst(a,n) (a[a.size()-1]>=n&&a[lower_bound(ALL(a),n)-a.begin()]==n?lower_bound(ALL(a),n)-a.begin():-1)
#define fist(s,t) ((int)s.find(t))
#define START int main(){cin.tie(0);ios::sync_with_stdio(false);
#define END }
using namespace std;
START
ll n; cin >> n;
vector<ll> a(n);
rep(i, 0, n)cin >> a[i];
sort(ALL(a));
cout << a[0];
rep(i, 1, n)cout << ' ' << a[i];
cout << endl;
END
