#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
int main(){
    const int MAX = 1000000000;
    int v, e, r;
    cin >> v >> e >> r;
    vector<pp> g[v];
    vector<int> d(v, MAX);
    for(int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(pp(t, d));
    }
    d[r] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> que;
    que.push(pp(r, 0));
    while(!que.empty()){
        pp p = que.top();
        que.pop();
        int v = p.first;
        if(d[v] < p.second) continue;
        for(pp next : g[v]){
            if(d[next.first] > d[v] + next.second){
                d[next.first] = d[v] + next.second;
                que.push(pp(next.first, d[next.first]));
            }
        }
    }
    for(int i = 0; i < v; i++){
        if(d[i] == MAX) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
