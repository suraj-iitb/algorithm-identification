#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF (1LL << 63)
struct edge{
    size_t to;
    size_t weight;
};

vector<size_t> dijkstra(vector<vector<edge>>& Graph, int& startPoint, int& vertexNum){
    vector<size_t> minimumWeight(vertexNum,INF);

    priority_queue<vector<pair<size_t,size_t>>, vector<pair<size_t,size_t>>, greater<pair<size_t,size_t>>> priorityQueue;
    priorityQueue.push({0,startPoint});
    minimumWeight[startPoint] = 0;

    while(!priorityQueue.empty()){
        pair<size_t,size_t> tmp = priorityQueue.top();

        edge Edge;
        Edge.to = tmp.second;
        Edge.weight = tmp.first;

        priorityQueue.pop();

        if(minimumWeight[Edge.to] < Edge.weight) continue;
        for(edge& edge : Graph[Edge.to]){
            if(minimumWeight[edge.to] < minimumWeight[Edge.to] + edge.weight) continue;
            minimumWeight[edge.to] = minimumWeight[Edge.to] + edge.weight;
            priorityQueue.push({minimumWeight[edge.to],edge.to});
        }
    }
    return minimumWeight;
}

int main(){
    int vertexNum, edgeNum, startPoint;
    cin >> vertexNum >> edgeNum >> startPoint;

    vector<vector<edge>> Graph(vertexNum);
    for(int i=0;i<edgeNum;i++){
        size_t from,to,weight;
        cin >> from >> to >> weight;
        Graph[from].push_back({to, weight});
    }

    vector<size_t> minimumWeight = dijkstra(Graph,startPoint,vertexNum);

    for(int i=0;i<vertexNum;i++){
        if(minimumWeight[i] == INF) cout << "INF" << '\n';
        else cout << minimumWeight[i] << '\n';
    }

}
