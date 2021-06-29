#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    int r;
    cin >> r;
    vector<vector<P>> G(n);
    for (int i = 0; i < m; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({d, t});
        // G[t].push_back({d, s});
    }
    priority_queue<P, vector<P>, greater<P>> que;
    int INF = 1001001001;
    vector<int> ans(n, INF);
    ans[r] = 0;
    que.push({0, r});
    while (!que.empty())
    {
        int d = que.top().fi;
        int v = que.top().se;
        que.pop();
        for (auto nv : G[v])
        {
            if (ans[nv.se] > d + nv.fi)
            {
                ans[nv.se] = d + nv.fi;
                que.push({ans[v] + nv.fi, nv.se});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << ans[i] << endl;
        }
    }

    return 0;
}

