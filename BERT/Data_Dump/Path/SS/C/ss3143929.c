#include <bits/stdc++.h>
#define N 100001
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> ii;
int n, e, r;
vector<ii> m[N];
int used[N];
int d[N];
void dijkstra(){
    d[r] = 0;
    used[r] = 1;
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(make_pair(0, r));//d[r]=0
    while(!q.empty()){
        ii temp = q.top(); q.pop();
        int u = temp.second;
        for(int i = 0; i < m[u].size(); i++){
            int v = m[u][i].second;
            if(used[v] == 0 && d[u]+m[u][i].first < d[v]){
                d[v] = d[u]+m[u][i].first;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &e, &r);
    for(int i = 0; i < n; i++) {
        used[i] = 0; d[i] = INF;
    }
    int a, b, c;
    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &a, &b, &c);
        m[a].push_back(make_pair(c, b));//m[a][b]=c
    }
    dijkstra();
    for(int i = 0; i < n; i++){
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
    return 0;
}
