#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cctype>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define INF 1000000000
#define MOD 1000000007
typedef long long ll;

using namespace std;

struct Node {
    int to;
    ll length;
    Node(){}
    Node(ll to, ll length) : to(to), length(length){};
};

bool operator>(const Node& ls, const Node& rs) {
    return ls.length > rs.length;
}
bool operator<(const Node& ls, const Node& rs) {
    return ls.length < rs.length;
}

int main(){
    int v,e,r; cin >> v >> e >> r;
    vector<vector<pair<int,int>>> edges(v, vector<pair<int,int>>(0));
    rep(i, e) {
        ll s,t,d; cin >> s >> t >> d;
        edges[s].push_back(make_pair(t,d));
    }
    vector<ll> ans(v, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(r,0));
    while(!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        if(top.length >= ans[top.to])
            continue;
        ans[top.to] = top.length;
        for(auto it = edges[top.to].begin(); it != edges[top.to].end(); it++) {
            pq.push(Node(it->first, top.length + it->second));
        }
    }
    for(ll i = 0; i < v; i++) {
        if(ans[i] != INF) {
            cout << ans[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
}


