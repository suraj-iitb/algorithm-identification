#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v;
    int n; cin >> n;
    rep(i, n) {int a; cin >> a; v.push_back(a);}
    rep(i, n) {if (i) cout << " "; cout << v[i];}
    cout << endl;
    rrep(i, 1, n) {
        int key = v[i];
        v.erase(v.begin() + i);
        //rep(j, v.size()) cout << v[j] << " "; cout << endl;
        int j = i - 1;
        while (v[j] > key && j >= 0) j--;
        v.insert(v.begin() + j + 1, key);
        rep(j, n) {if (j) cout << " "; cout << v[j];}
        cout << endl;
    }
    
    
}

