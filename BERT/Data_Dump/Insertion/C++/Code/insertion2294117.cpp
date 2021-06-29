//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
//if it can you can use
//#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (auto i=(a);i<(b);i++)
#define RFOR(i,a,b) for (auto i=(b)-1;i>=(a);i--)
#define REP(i,n) for (auto i=0;i<(n);i++)
#define RREP(i,n) for (auto i=(n)-1;i>=0;i--)
#define EACH(i,v) for(auto i : v)
#define inf INT_MAX/3
#define INF INT_MAX/3
#define eps 1e-15
#define EPS 1e-15
#define TEN9 1000000000
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define mii map<int,int>
#define msd map<string,double>
#define msi map<string,int>
#define ti3 tuple<int,int,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define FST first
#define SEC second
#define SORT(v) sort(ALL(v));
#define VVI(v,n1,n2) vector<vector<int> > v(n1, vector<int>(n2, 0));
#define int(x) int x; scanf("%d",&x);
#define lint(x) long long x; scanf("%lld",&x);
#define vint(v,n) vector<int> v(n); REP(i,n) scanf("%d", &v[i]);
#define vvint(v,n1,n2) vector<vector<int> > v(n1, vector<int>(n2, 0)) ; REP(i,n1) REP(j,n1) scanf("%d", &v[i][j]);
#define vlint(v,n) vector<ll int> v(n); REP(i,n) scanf("%lld", &v[i]);
#define vvlint(v,n1,n2) vector<vector<ll int> > v(n1, vector<ll int>(n2, 0)); REP(i,n1) REP(j,n1) scanf("%lld", &v[i][j]);
#define double(x) double x; scanf("%lf",&x);
#define vdouble(v,n) vector<double> v(n); REP(i,n) scanf("%lf", &v[i]);
#define vvdoube(v,n1,n2) vector<vector<double> > v(n1, vector<double>(n2, 0)); REP(i,n1) REP(j,n1) scanf("%lf", &v[i][j]);
#define char(x) char x; scanf("%c",&x);
#define vchar(v,n) vector<char> v(n); REP(i,n) scanf("%c", &v[i]);
#define vvchar(v,n1,n2) vector<vector<char> > v(n1, vector<char>(n2, 0)); REP(i,n1) REP(j,n1) scanf("%c", &v[i][j]);
#define string(x) string x; cin >> x;
#define vstring(v,n) vector<string> v(n); REP(i,n) cin >> v(i);

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]));

// const int dy4[]={0, 0, 1, -1};
// const int dx4[]={1, -1, 0, 0};
// const int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
// const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// ll int combi(ll int n, ll int k) {
//     uint64_t r = 1;
//     for (uint64_t d = 1; d <= k; ++d) {
//         r *= n--;
//         r /= d;
//     }
//     return r;
// }

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        int v = a[i];
        int j = i-1;
        while (a[j] > v && j >= 0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for (size_t i = 0; i < n; i++) {
            if(i>0) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
