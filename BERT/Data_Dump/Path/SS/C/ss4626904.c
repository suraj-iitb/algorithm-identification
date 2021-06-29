#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define N 500000
#define INF 2e9
typedef pair<int, int> P;
int V, E, r;
vector<P> path[500000];
int flag[100000];
int dijkstra(int s){
    for(int i = 0; i < V; i++){
        flag[i] = -INF;
    }
    priority_queue<P> pq;
    pq.push(MP(0, s));
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        if(flag[p.S] > p.F){
            continue;
        }
        flag[p.S] = p.F;
        for(auto i = path[p.S].begin(); i != path[p.S].end(); i++){

            if(flag[(*i).F] == -INF){
                pq.push(MP(p.F + (*i).S, (*i).F));
            }
        }
    }
}
int main(){
    cin >> V >> E >> r;
    for(int i = 0; i < E; i++){
        int temp, temp2, temp3;
        cin >> temp >> temp2 >> temp3;
        path[temp].push_back(MP(temp2, -temp3));
    }
    dijkstra(r);
    for(int i = 0; i < V; i++){
        if(flag[i] == -INF){
            cout << "INF" << endl;
        }
        else{
            cout << -flag[i] << endl;
        }
    }
}
