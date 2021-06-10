
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <limits>
#include <queue>
using namespace std;


class FromSrc{
public:
    int dist_id;
    int length;

    FromSrc(int id, int length): dist_id(id), length(length){};

};

using adj_list = vector< list< FromSrc> >;

bool operator>(const FromSrc& p1, const FromSrc& p2){
    return p1.length > p2.length;
}

bool operator<(const FromSrc& p1, const FromSrc& p2){
    return p1.length < p2.length;
}

int int_max = numeric_limits<int>::max();


vector<int> dicstra(int V, int r, const adj_list& adj){

    vector<int> table(V, int_max);
    table[r] = 0;

    priority_queue<FromSrc, vector<FromSrc>, greater<> > Q;
    for(int i = 0; i < V; i++) Q.push(FromSrc(i, table[i]));


    while(!Q.empty()){
        auto next_path = Q.top(); Q.pop();

        int u = next_path.dist_id;
        int path_to_u = next_path.length;

        if( path_to_u > table[u]) continue;//over written element
        if (next_path.length == int_max) break; // lest are unreachable

        for(const auto& from_u: adj[u]){
            int w = from_u.dist_id;
            int new_path = path_to_u + from_u.length;
            if( new_path < table[w] ){
                table[w] = new_path;
                Q.push(FromSrc{w, new_path}); //virtually over write
            }
        }


    }

    return table;

}

int main(){
    int V,E,r; cin >> V >> E >> r;

    adj_list adj(V);


    for(int i = 0; i < E; i++){
        int s,t,d; cin >> s >> t >> d;
        adj[s].push_back(FromSrc{t,d});
    }

    vector<int> table = dicstra(V, r, adj );

    for(int i = 0; i < V; i++){
     int dist = table[i];
     if (dist == int_max){
         cout << "INF" << endl;
     }
     else{
         cout << dist << endl;
     }
    }

    return 0;
}

