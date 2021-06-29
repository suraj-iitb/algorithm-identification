#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100000
#define EMAX 500000
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFTY 1 << 30
int v,r;
vector<pair<int,int> > adj[EMAX];

void DIJKSTRAHOU(){
    priority_queue<pair<int,int> > PQ;
    int color[MAX];
    int d[MAX];
    for(int i = 0; i < v; i++){
        color[i] = WHITE;
        d[i] = INFTY;
    }

    d[r] = 0;
    PQ.push(make_pair(0,r));
    color[r] = GRAY;

    while(!PQ.empty()){
        pair<int,int> m = PQ.top(); PQ.pop();
        int x = m.second;
        color[x] = BLACK;

        if(d[x] < m.first*(-1)) continue;

        for(int i = 0; i < adj[x].size(); i++){
            int v = adj[x][i].first;
            if(color[v] == BLACK) continue;
            if(d[x]+adj[x][i].second < d[v]){
                d[v] = d[x]+adj[x][i].second;
                PQ.push(make_pair(d[v]*(-1),v));
                color[v] = GRAY;
            }
        }
    }
        for(int i = 0; i < v; i++){
          if(d[i] < INFTY) printf("%d\n",d[i]);
          else printf("INF\n");
    }
}

int main(void){
    int e,s,t,d;
    scanf("%d %d %d", &v, &e, &r);
    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &s, &t, &d);
        adj[s].push_back(make_pair(t,d));
    }
    DIJKSTRAHOU();

    return 0;
}

