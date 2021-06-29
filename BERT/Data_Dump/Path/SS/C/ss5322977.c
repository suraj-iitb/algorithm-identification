#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<set>

#define MAX 100005
#define INF 2000000000

int dist[MAX];

std::set < std::pair < int, int > > se;
std::set < std::pair < int, int > > ::iterator it;
std::vector < std::pair < int, int > > graph[500005];

void Init()
{
    se.clear();
    for (int i = 0; i < MAX; i++)graph[i].clear();
    for (int i = 0; i < MAX; i++)dist[i] = INF;
}

void Stra(int s)
{
    dist[s] = 0;
    se.insert(std::make_pair(0, s));
    while (!se.empty()) {
        it = se.begin();
        int d = (*it).first;
        int u = (*it).second;
        se.erase(it);
        int si = graph[u].size();
        for (int i = 0; i < si; i++) {
            int v = graph[u][i].first;
            int cost = graph[u][i].second;
            if (dist[v] > d + cost) {
                dist[v] = d + cost;
                se.insert(std::make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    int n, e, s, u, v, c;
    while (~scanf("%d %d %d", &n, &e, &s)) {
        Init();
        for (int i = 1; i <= e; i++) {
            scanf("%d %d %d", &u, &v, &c);
            graph[u].push_back(std::make_pair(v, c));
        }
        Stra(s);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)printf("INF\n");
            else printf("%d\n", dist[i]);
        }
    }
    return 0;
}
