#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define max 100001
#define inf 1000000000

vector<pair<int,int> > Graph[max];
vector<int> cost;
priority_queue<pair<int,int> > PQ_Graph;

int vertex, edge;
int start_vertex;

void Init_Graph();
void Init_Cost();
void PQ_Dijkstra();


int main(){

    cin>>vertex>>edge>>start_vertex;

    //initialize and setting 
    Init_Graph();

    //do dijkstra
    PQ_Dijkstra();

    for(int i=0;i<vertex;i++){
        if(cost[i] != inf) cout<<cost[i]<<endl;
        else cout<<"INF"<<endl;
    }

    return 0;
}


//initialize and setting graph
void Init_Graph(){
    int source, target, weight;

    //initialize
    for(int j=0;j<edge;j++){
        cin>>source>>target>>weight;
        Graph[source].push_back(make_pair(target, weight));
    }
    
}


//initialize array of visit and cost
void Init_Cost(){
    //change the element
    cost.resize(vertex);

    //initialize 
    for(int i=0;i<vertex;i++){
        cost[i] = inf;
    }
}


//do Dijkstra's Algorithm by priority queue
void PQ_Dijkstra(){
    int candi_vertex;
    int adj_vertex;
    pair<int, int> keep;

    //initialize
    Init_Cost();

    //setting for the start vertex
    cost[start_vertex] = 0;
    PQ_Graph.push(make_pair(0, start_vertex));


    //Dijkstra's search by priority queue
    while(1){
        if(PQ_Graph.empty() == 1){
            break;
        }
        
        keep = PQ_Graph.top(); 
        PQ_Graph.pop();
        candi_vertex = keep.second;


        if(cost[candi_vertex] < keep.first * (-1)){
            continue;
        } 

        for(int i=0;i<Graph[candi_vertex].size();i++){
            adj_vertex = Graph[candi_vertex][i].first;

            if(cost[adj_vertex] > cost[candi_vertex] + Graph[candi_vertex][i].second){
                cost[adj_vertex] = cost[candi_vertex] + Graph[candi_vertex][i].second;
                PQ_Graph.push(make_pair(cost[adj_vertex] * (-1), adj_vertex));
            }
        }
    }
    
}
