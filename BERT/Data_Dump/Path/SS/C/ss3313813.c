#include <iostream>
#include <forward_list>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

#define INFINITE INT_MAX
#define _for(j,N) for(int i = (j);i < (N);++i)

vector<long> wt;
vector<bool> pre;

class HeapNode{
public:
    int v;
    long wt;
    HeapNode(int vi,long wti):v(vi),wt(wti){;}
    bool operator < (const HeapNode& rhs) const{
        return wt > rhs.wt;
    }
};

priority_queue<HeapNode> pq;

class Graph{
public:
    int V;
    int E;
    vector<forward_list<HeapNode>> adj;
    Graph(int v,int e):V(v),E(e){
        adj.resize(V);
        wt.resize(V);
        pre.resize(V);
        _for(0,V) {pre[i] = false;wt[i] = INFINITE;}
    }

    void addEdge(int v,int w,long wt){adj[v].push_front(HeapNode(w,wt));}
    void distra(int v);
};


void Graph::distra(int v){
    wt[v] = 0;
    pq.push(HeapNode(v,0));

    while(!pq.empty()){
        int w = pq.top().v;
        pq.pop();
        if(pre[w]) continue;

        pre[w] = true;
        for(auto a = adj[w].begin();a != adj[w].end();++a){
            int t = (*a).v;
            long wt_now = (*a).wt;

            if(wt[t] > wt_now + wt[w]){
                wt[t] = wt_now + wt[w];
                pq.push(HeapNode(t,wt[t]));
            }
        }
    }
}

int main()
{
    int V,E,r;
    int s,t,w;
    scanf("%d %d %d",&V,&E,&r);
    Graph G(V,E);
    _for(0,E){
        scanf("%d %d %d",&s,&t,&w);
        G.addEdge(s,t,w);
    }

    G.distra(r);

    _for(0,V){
        if(wt[i] == INFINITE) printf("INF\n");
        else printf("%ld\n",wt[i]);
    }
    return 0;
}

