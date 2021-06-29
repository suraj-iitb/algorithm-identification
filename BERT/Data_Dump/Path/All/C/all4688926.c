#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cctype>
#include <set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define INF 10000000007
#define MOD 1000000007
typedef long long ll;

using namespace std;

int main(){
    int v,e; cin >> v >> e;
    vector<unordered_map<int, ll>> edges(v);
    queue<int> q;
    set<int> se;
    vector<vector<ll>> table(v, vector<ll>(v, INF));
    rep(i, e) {
        ll s, t, d; cin >> s >> t >> d;
        edges[s][t] = d;
        table[s][t] = d;
        if(se.find(s) == se.end()) {
            se.insert(s);
            q.push(s);
        }
    }

    rep(i, v) {
        table[i][i] = 0;
    }
    int itr = 0;
    while(!q.empty()) {
        if(itr > 1000000) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
        itr++;
        int popped = q.front();
        q.pop();
        for(auto it = edges[popped].begin(); it != edges[popped].end(); it++) {
            for(int i = 0; i < v; i++) {
                if(table[i][popped] == INF)
                    continue;
                if(table[i][popped] + it->second < table[i][it->first]) {
                    table[i][it->first] = table[i][popped] + it->second;
                    q.push(it->first);
                }
            }
        }
    }
    rep(i, v) {
        rep(j, v) {
            if(table[i][j] == INF) {
                cout << "INF";
            } else {
                cout << table[i][j];
            }
            if(j != v-1)
                cout << ' ';
        }
        cout << endl;
    }
}


