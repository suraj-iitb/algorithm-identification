#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 10;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

void print_line(vector<ll> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}


typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;
const int mod = 1000000007;

typedef pair<ll, ll> P;


void counting_sort(vector<ll> &a, vector<ll> &b, ll k, ll n) {
    vector<ll> c(k + 1, 0);
    rep(i, n) c[a[i]]++;
    for (int i = 1; i <= k; i++) c[i] = c[i] + c[i - 1];
    for (ll i = n - 1; i >= 0; i--) {
        ll ae = a[i];
        ll aec = c[ae];
        b[aec - 1] = ae;
        c[ae]--;
    }
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    ll k = *max_element(a.begin(), a.end());
    counting_sort(a, b, k, n);
    print_line(b);
}

