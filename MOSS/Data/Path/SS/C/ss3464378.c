#include<bits/stdc++.h>
using namespace std;
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2233614#1
#define PI 3.1415926535897932
typedef pair<int, int> pii;
template <typename T>
struct edge {
    int from, to;
    T cost;
    edge(int s, T d): to(s),cost(d) {}
    edge(int f, int s, T d): from(f), to(s), cost(d) {}
    bool operator<(const edge &e) const {
        return cost<e.cost;
    }
    bool operator>(const edge &e) const {
        return cost>e.cost;
    }
};

#define Graph(type) vector< vector< edge<type> > >

int main(){
    int mod=1000000007;
    int v,e,start;
    scanf("%d %d %d",&v,&e,&start);
    Graph(int) g(v);
    for(int i=0;i<e;i++) {
        int s,t,d;
        scanf("%d %d %d",&s,&t,&d);
        g[s].push_back(edge<int>(t,d));
    }

    vector<bool> inq(v, false);
    queue<int> que;
    vector<int> rec(v, 1<<30);
    que.push(start);
    inq[start]=true;
    rec[start]=0;

    while(!que.empty()) {
        int point = que.front(); que.pop();
        inq[point]=false;
        for(size_t i=0;i<g[point].size();i++) {
            edge<int> next=g[point][i];
            int to = next.to, cost=next.cost;
            if(rec[to]>rec[point]+cost) {
                rec[to]=rec[point]+cost;
                if(!inq[to]) {
                    inq[to]=true;
                    que.push(to);
                }
            }
        }
    }
    for (int i=0;i<v;i++) {
        if(rec[i]!=1<<30) printf("%d\n",rec[i]);
        else printf("INF\n");
    }
    return 0;
}


