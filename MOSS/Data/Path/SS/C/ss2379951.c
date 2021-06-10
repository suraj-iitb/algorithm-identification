#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1001001001
using namespace std;
typedef pair<int,int> P;

int main() {
    int V,E,r;
    cin >> V >> E >> r;

    vector< vector<int> > path(V);        //??£??\?????????
    map<P, int> w;         //???????????????

    int s,t,d;
    for(int i=0; i<E; i++) {
        cin >> s >> t >> d;
        path[s].push_back(t);
        w[P(s,t)] = d;
    }

    vector<int> distance(V,INF);      //?§????????????????????????§????????????????????????
    distance[r] = 0;
    unordered_set<int> Q;                     //????????????????????????????¢??????????????????????
    for(int i=0; i<V; i++) {Q.insert(i);}

    priority_queue<P, vector<P>, greater<P> > S;
    S.push(P(distance[r], r));

    while(Q.size() && S.size()) { 
        P tmp = S.top();
        S.pop();
        int u = tmp.second;
        if(Q.find(u) != Q.end()) {
            Q.erase(u);
            for(int v : path[u]) {
                    distance[v] = min(distance[v], distance[u] + w[P(u,v)]);
                    S.push(P(distance[v], v));
            }
        }
    }

    for(int i=0; i<V; i++) {
        if(distance[i] != INF) {
            cout << distance[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
}
