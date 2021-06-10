#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int V, E, r;
const long long INF = 1e12;
struct pqdata {
    int no;
    long long d;
    bool operator<(const pqdata &r) const { return d > r.d; }
};

struct graphdata {
    int to; long long dist;
};

vector< vector<graphdata> > graph(100100, vector<graphdata>());

int main() {
    cin >> V >> E >> r;
    for(int i = 0; i < E; ++i) {
        int s;
        graphdata indata;
        cin >> s >> indata.to >> indata.dist;
        graph.at(s).push_back(indata);
    }

    priority_queue<pqdata> pque;
    pqdata first;
    first.no = r; first.d = 0;
    pque.push(first);
    vector<long long> ans(V, INF);
    ans.at(r) = 0;
    while(!pque.empty()) {
        pqdata now = pque.top();
        pque.pop();
        if(ans.at(now.no) < now.d) continue;
        for(int i = 0; i < graph.at(now.no).size(); ++i) {
            pqdata next;
            next.no = graph.at(now.no).at(i).to; next.d = now.d+graph.at(now.no).at(i).dist;
            if(ans.at(next.no) > next.d) {
                ans.at(next.no) = next.d;
                pque.push(next);
            }
        }
    }

    for(int i = 0; i < V; ++i) {
        if(ans.at(i) == INF) cout << "INF" << endl;
        else cout << ans.at(i) << endl;
    }
}
