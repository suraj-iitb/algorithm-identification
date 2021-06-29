#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <assert.h>
using Int = long long;
constexpr Int inf = 1e17;
void heap_dijkstra(const Int& V,const Int& e,const Int& s){
    std::vector<std::vector<std::pair<Int,Int>>>edge(V,std:: vector<std::pair<Int,Int>>());
    for(int i = 0; i < e; ++i){
        std::pair<Int,Int> a;
        int c;
        std::cin >> a.first >> a.second >> c;
        edge[a.first].emplace_back(a.second,c);
    }
    std::vector<Int>d(V,inf);
    d[s] = 0;
    std:: priority_queue<std::pair<Int,Int>,std::vector<std::pair<Int,Int>>,std::greater<>>que;
    que.emplace(d[s],s);
    std::vector<Int>validate(V,inf);
    while(not que.empty()){
        const auto now = que.top(); que.pop();
        Int cv = now.second; Int cd = now.first;
        if(d[cv] < cd) {/*assert(false); is RE */   continue; }
        assert(validate[cv] == inf);
        validate[cv] = 0;
        for(const auto& next : edge[cv]){
            // No need to update
            if(cd + next.second >= d[next.first])continue;
            //the vertex which is updated will never update
            //assert(d[next.first] != inf);
            d[next.first] = d[cv] + next.second;
            que.emplace(d[next.first],next.first);
        }
    }
    for(int v=0; v<V;v++)
        if(d[v] == inf)std::cout<<"INF"<<std::endl;
        else std::cout << d[v] << std::endl;
}
int main(){
    long long V,e,s;
    std:: cin >> V >> e >> s;
    heap_dijkstra(V,e,s);
}
